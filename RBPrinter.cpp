#include "RBPrinter.h"
#include <iostream>
#include <QDebug>
#include <QTextCodec>
#include <QDateTime>

#include "winbase.h"
#include "bxlconst.h"
#include "Menu.h"


#define BXLPAPI __declspec(dllimport)

typedef int (CALLBACK *fnStatusCallbackFunc)(int nStatus);

BXLPAPI long __stdcall PrinterOpen(int nInterface,
                                       LPCTSTR szPortName = L"",
                                       int nBaudRate = CBR_115200, // Socket (Ethernet) : Port number, Serial : BaudRate
                                       int nDataBits = DATABITS_8,
                                       int nParity = NOPARITY,
                                       int nStopBits = ONESTOPBIT,
                                       int nFlowControl = 0);

BXLPAPI long __stdcall PrinterOpenW(int nInterface,
                                   LPCWSTR szPortName = L"",
                                   int nBaudRate = CBR_115200, // Socket (Ethernet) : Port number, Serial : BaudRate
                                   int nDataBits = DATABITS_8,
                                   int nParity = NOPARITY,
                                   int nStopBits = ONESTOPBIT,
                                   int nFlowControl = 0);

BXLPAPI long __stdcall ConnectSerial(LPCTSTR szPortName,
                                         int nBaudRate,
                                         int nDataBits = DATABITS_8,
                                         int nParity = NOPARITY,
                                         int nStopBits = ONESTOPBIT,
                                         int nFlowControl = 0);

BXLPAPI long __stdcall ConnectSerialW(LPCWSTR szPortName,
                                     int nBaudRate,
                                     int nDataBits = DATABITS_8,
                                     int nParity = NOPARITY,
                                     int nStopBits = ONESTOPBIT,
                                     int nFlowControl = 0);

BXLPAPI long __stdcall ConnectParallel(LPCSTR szPortName);
BXLPAPI long __stdcall ConnectParallelW(LPCWSTR szPortName);
BXLPAPI long __stdcall ConnectNet(LPCSTR szIpAddr, int nPortNum);
BXLPAPI long __stdcall ConnectNetW(LPCWSTR szIpAddr, int nPortNum);

BXLPAPI long __stdcall ConnectUsb();
BXLPAPI long __stdcall PrinterClose();

BXLPAPI long __stdcall InitializePrinter();

BXLPAPI long __stdcall GetStat();
BXLPAPI long __stdcall GetPrinterCurrentStatus();
BXLPAPI long __stdcall CheckPrinter();

BXLPAPI long __stdcall PrintText(LPCSTR Data, long Alignment, long Attribute, long TextSize);
BXLPAPI long __stdcall PrintTextW(LPCWSTR Data, long Alignment, long Attribute, long TextSize, long lCodePage = CP_ACP);
BXLPAPI long __stdcall PrintTextInImage(LPCSTR Data, LPCSTR FontName, BOOL Italic, BOOL Bold, BOOL Underline, int FontSize, int Alignment);
BXLPAPI long __stdcall PrintTextInImageW(LPCWSTR Data, LPCWSTR FontName, BOOL Italic, BOOL Bold, BOOL Underline, int FontSize, int Alignment);
BXLPAPI long __stdcall LineFeed(int nFeed);
BXLPAPI long __stdcall PrintBitmap(LPCSTR FileName, long Width, long Alignment, long Level, BOOL bDithering);
BXLPAPI long __stdcall PrintBitmapW(LPCWSTR FileName, long Width, long Alignment, long Level, BOOL bDithering);
BXLPAPI long __stdcall GetPrintBitmapBuf(LPCSTR fileName, long Width, long Level, BOOL bDithering, PBYTE pOutBuffer, DWORD cbBuf, LPDWORD pcbNeeded);
BXLPAPI long __stdcall GetPrintBitmapBufW(LPCWSTR fileName, long Width, long Level, BOOL bDithering, PBYTE pOutBuffer, DWORD cbBuf, LPDWORD pcbNeeded);
BXLPAPI long __stdcall PrintBarcode(PCHAR Data, long Symbology, long Height, long Width, long Alignment, long TextPosition);
BXLPAPI long __stdcall PrintQRCode(PCHAR Data, long Model, long ModuleSize, long EccLevel, long Alignment);
BXLPAPI long __stdcall PrintQRCodeW(LPCWSTR Data, long model, long moduleSize, long eccLevel, long alignment);
BXLPAPI long __stdcall PrintPDF417(PCHAR Data, long Type, long columnNumber, long rowNumber, long moduleWidth, long moduleHeight, long eccLevel, long alignment);
BXLPAPI long __stdcall PrintDataMatrix(PCHAR Data, long ModuleSize, long Alignment);
BXLPAPI long __stdcall PrintGS1DataBar(PCHAR Data, long Symbology, long ModuleSize, long Alignment);
BXLPAPI long __stdcall PrintCompositeSymbology(PCHAR Data1d, long Symbol1d, PCHAR Data2d, long Symbol2d, long ModuleSize, long Alignment);

BXLPAPI long __stdcall SetCharacterSet(long Value);
BXLPAPI long __stdcall SetInterChrSet(long Value);
BXLPAPI long __stdcall GetCharacterSet();
BXLPAPI long __stdcall GetInterChrSet();

BXLPAPI long __stdcall SetUpsideDown(long mode);
BXLPAPI long __stdcall SetLeftMargin(long margin);
BXLPAPI long __stdcall SetPrintWidth(long width);

BXLPAPI long __stdcall CutPaper();
BXLPAPI long __stdcall DirectIO(PCHAR Data, UINT uiWrite, PCHAR pRequest, UINT& uiRead);
BXLPAPI long __stdcall WriteBuff(PBYTE pBuffer, long lNumberOfBytesToWrite, long& lWritten);
BXLPAPI long __stdcall ReadBuff(PBYTE pBuffer, long lNumberOfBytesToRead, long& lReaded);
BXLPAPI long __stdcall GetPrinterDPI(UINT& uiDPI);

BXLPAPI long __stdcall ClearScreen();
BXLPAPI long __stdcall ClearLine(long line);
BXLPAPI long __stdcall DisplayString(LPCSTR Data);
BXLPAPI long __stdcall DisplayStringW(LPCWSTR Data, long codepage);
BXLPAPI long __stdcall DisplayStringAtLine(long line, LPCSTR Data);
BXLPAPI long __stdcall DisplayStringAtLineW(long line, LPCWSTR Data, long codepage);

BXLPAPI long __stdcall StoreImageFile(LPCSTR FileName, long index);
BXLPAPI long __stdcall StoreImageFileW(LPCWSTR FileName, long index);

BXLPAPI long __stdcall DisplayImage(long index, long x, long y);
BXLPAPI long __stdcall SetInternationalCharacterset(long characterSet);
BXLPAPI long __stdcall OpenDrawer(long pinNumber);

BXLPAPI long __stdcall SetPagemode(long pageMode);
BXLPAPI long __stdcall SetPagemodePrintArea(long x, long y, long width, long height);
BXLPAPI long __stdcall SetPagemodeDirection(long direction);
BXLPAPI long __stdcall SetPagemodePosition(long x, long y);

BXLPAPI long __stdcall TransactionStart();
BXLPAPI long __stdcall TransactionEnd(BOOL SendCompletedCheck, long Timeout);

BXLPAPI long __stdcall PaperEject(int option);
BXLPAPI long __stdcall GetPresenterStatus();

// Provides notification regarding the call of the callback function notifying the application when printer's status changes.
BXLPAPI long __stdcall BidiSetCallBack(fnStatusCallbackFunc pStatusCallbackFn);
BXLPAPI long __stdcall BidiCancelCallBack();

extern RBLog *rblog;
extern Menu *menu;



using namespace std;
RBPrinter::RBPrinter()
{
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));


    RBOpenPort("COM5");

//    RBPrintCheckOut("좀 잘 하자\n\n\n\n\n\n\neverything is ok");
//    RBPrintReceipt(0,"망고에이드", 2500, "우리카드", "538920******3085", "572168734", "20200707");
//    RBPrintText();
}

int RBPrinter::CountLength(QString name){
    int temp_len = name.length()*2;
    int len = temp_len;
//    qDebug()<<name;
    for(int i=0; i<name.length(); i++){
        char temp_char = name.at(i).toLatin1();
        if(temp_char == 'I' || temp_char == 'c' || temp_char == 'e' ||
                temp_char == 'H' || temp_char == 'o' || temp_char == 't' ||
                temp_char == 'L' || temp_char == 'a' || temp_char == 'A' ||
                temp_char == ' '){
//            qDebug()<<temp_char;
            len--;
        }
    }
    return len;
}

int RBPrinter::RBOpenPort(QString com){
    int nIF = ISerial;
    LPCWSTR com2 = (const wchar_t*)com.utf16();
    int nRes = PrinterOpenW(nIF, com2, 9600);
    qDebug() << "Printer Open: " << nRes;
//    rblog->AddLogLine("[RBPrinter] Printer Open : " + QString().sprintf("%d",nRes));
    return nRes;
}


//void RBPrinter::RBClosePort(){
//    ClosePort();
//}

void RBPrinter::RBCheckStatus(){
    Status = GetPrinterCurrentStatus();
}

int RBPrinter::RBPrintReceipt(QString pin, QVector<ST_ORDER_INFO> menu_list){

    qDebug() << "PrintReceipt";

    if(TransactionStart()!=BXL_SUCCESS){
        qDebug() << "[RBPrinter]  Print transaction Fail";
    }

    if(InitializePrinter()!=BXL_SUCCESS){

        qDebug() << "[RBPrinter]  Print initialize Fail";
    }

//        SetCharacterSet(BXL_CS_KS5601);
//        SetInterChrSet(BXL_ICS_KOREA);

//    int ret = PrintBitmapW(L"boba_logo.bmp", BXL_WIDTH_NONE, BXL_ALIGNMENT_CENTER, 50, TRUE);

    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT |BXL_FT_BOLD | BXL_FT_UNDERLINE, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);


    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString mon_sun_format = "ddd";
    QString date_format = "yyyy년 MM월 dd일";
    QString time_format = "hh:mm";
    QString mon_sun_str = QDateTime::currentDateTime().toString(mon_sun_format);


    QString date_str = QDateTime::currentDateTime().toString(date_format) + "(" + mon_sun_str + ")";
    QString time_str = " " + date_str +  " " + QDateTime::currentDateTime().toString(time_format) + " 레인보우 로보틱스\n";

    qDebug() << "1";
    PrintTextW(time_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    // 3 + 4 + 10 + 3
    QString temp_str = "상 품 명";
    PrintTextW(temp_str.toStdWString().data(), BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    qDebug() << "11";
    for(int i=0; i<menu_list.size(); i++){
        QString menu_str = menu_list[i].menu_name;
        qDebug() << menu_str;
        PrintTextW(menu_str.toStdWString().data(), BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
        PrintTextW(L"\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    }
    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    qDebug() << "2";
    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
//    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString pin_str = "주문번호 : " + pin;
    PrintTextW(pin_str.toStdWString().data(), BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);

    PrintTextW(L"\n\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    char barcode_char[20];
//    sprintf(barcode_char, "01977%s\0", pin.toStdString().data());
//    PrintBarcode(barcode_char, BXL_BCS_ITF, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_BELOW);
    sprintf(barcode_char, "a%sz\0", pin.toStdString().data());
//    PrintBarcode(barcode_char, BXL_BCS_CODE128, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_NONE);

    PrintQRCode(barcode_char, BXL_QRCODE_MODEL1,100,BXL_QRCODE_ECC_LEVEL_M,BXL_ALIGNMENT_CENTER);
    //PrintBarcode(barcode_char, BXL_BCS_ITF, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_NONE);

    PrintTextW(L"\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    PrintTextW(L"※ 픽업시 영수증의 바코드가 필요하니 영수증을 버리지 않고 꼭 소지해주세요!\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"※ 오른쪽 주문 완료 현황판에 주문번호 확인 후 바코드 리더기에 영수증의 바코드를 찍으면 음료가 나옵니다.\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);



//    OpenDrawer(BXL_CASHDRAWER_PIN5);
    CutPaper();

//    LineFeed(2);

    PaperEject(BXL_EJT_HOLD);

    if(TransactionEnd(TRUE, 3000 /* 3 seconds */) != BXL_SUCCESS){
        // failed to read a response from the printer after sending the print-data.
//        MessageBox(_T("TransactionEnd failed."), NULL, MB_OK|MB_ICONERROR);
    }else{

    }
    qDebug() << "5";

    return 0;
}

int RBPrinter::RBPrintText(){

    // Enters 'Transaction' mode.
    TransactionStart();

    InitializePrinter();
//    SetCharacterSet(BXL_CS_WPC1252);
//    SetInterChrSet(BXL_ICS_USA);

    PrintText("Receipt", BXL_ALIGNMENT_CENTER, BXL_FT_BOLD | BXL_FT_UNDERLINE, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);
    PrintText(" \n\n", BXL_ALIGNMENT_CENTER, BXL_FT_BOLD | BXL_FT_UNDERLINE, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);


    PrintText("------------------------------\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText(" 사과      3             $3.0\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText(" 콜라       1             $1.2\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText(" Milk       2             $1.8\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText(" Juice      1             $2.0\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText("------------------------------\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText(" Total                    $8.0\n", BXL_ALIGNMENT_CENTER, BXL_FT_BOLD, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText(" Cash                     $8.0\n", BXL_ALIGNMENT_CENTER, BXL_FT_BOLD, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText("                          $0.0\n", BXL_ALIGNMENT_CENTER, BXL_FT_BOLD, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintText("Test", BXL_ALIGNMENT_CENTER, BXL_FT_BOLD, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText("BBB", BXL_ALIGNMENT_CENTER, BXL_FT_FONTB | BXL_FT_BOLD, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText("CCC", BXL_ALIGNMENT_CENTER, BXL_FT_FONTB | BXL_FT_REVERSE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText("DDD", BXL_ALIGNMENT_CENTER, BXL_FT_BOLD | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintText("\n", BXL_ALIGNMENT_CENTER, BXL_FT_BOLD | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintBarcode((char*)("12345678"), BXL_BCS_ITF, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_BELOW);

    //OpenDrawer(BXL_CASHDRAWER_PIN2);
    OpenDrawer(BXL_CASHDRAWER_PIN5);
    CutPaper();

    //Only BK3-31 with presenter supported
    PaperEject(BXL_EJT_HOLD);
    //////////////////////////////////////

    // Leaves 'Transaction' mode, and then sends print data in the buffer to start printing.
    if(TransactionEnd(TRUE, 3000 /* 3 seconds */) != BXL_SUCCESS){
        // failed to read a response from the printer after sending the print-data.
//        MessageBox(_T("TransactionEnd failed."), NULL, MB_OK|MB_ICONERROR);
    }

    return 1;
}
