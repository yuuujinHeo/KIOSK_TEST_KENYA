#include "RBPrinter.h"
#include <iostream>
#include <QDebug>
#include <QTextCodec>
#include <QDateTime>

#include "winbase.h"
#include "bxlconst.h"


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
    rblog->AddLogLine("[RBPrinter] Printer Open : " + QString().sprintf("%d",nRes));
    return nRes;
}


//void RBPrinter::RBClosePort(){
//    ClosePort();
//}

void RBPrinter::RBCheckStatus(){
    Status = GetPrinterCurrentStatus();
}

int RBPrinter::RBPrintCheckOut(QString content){
    if(TransactionStart()!=BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter]  Print transaction Fail");
    }

    if(InitializePrinter()!=BXL_SUCCESS){

        rblog->AddLogLine("[RBPrinter]  Print initialize Fail");
    }

    LineFeed(2);
    PrintTextW(content.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    CutPaper();
    PaperEject(BXL_EJT_HOLD);
    if(TransactionEnd(TRUE, 3000 /* 3 seconds */) != BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter] RBPrintCheckOut Fail: " + content.left(10));
        // failed to read a response from the printer after sending the print-data.
//        MessageBox(_T("TransactionEnd failed."), NULL, MB_OK|MB_ICONERROR);
    }else{
        rblog->AddLogLine("[RBPrinter] RBPrintCheckOut Success: " + content.left(10));
        
    }
    return 0;
}

int RBPrinter::RBPrintReceipt(QString pin, QVector<ST_ORDER_INFO> menu_list, int price, QString card_comp, QString card_num,
                              QString approve_num, QString tran_date){

    qDebug() << "PrintReceipt";
    if(TransactionStart()!=BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter]  Print transaction Fail");
    }

    if(InitializePrinter()!=BXL_SUCCESS){

        rblog->AddLogLine("[RBPrinter]  Print initialize Fail");
    }

//        SetCharacterSet(BXL_CS_KS5601);
//        SetInterChrSet(BXL_ICS_KOREA);

//    int ret = PrintBitmapW(L"boba_logo.bmp", BXL_WIDTH_NONE, BXL_ALIGNMENT_CENTER, 50, TRUE);

    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT |BXL_FT_BOLD | BXL_FT_UNDERLINE, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);


    PrintTextW(L"대보디앤에스(주)옥산(하)휴게소\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"[사업자번호] 301-81-23531      \n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"[주소] 충청북도 청주시 흥덕구 옥산면 경부고속도로 309  ☎ 043-260-1053\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


//    PrintTextW(L"대전광역시청 새마을금고\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
//    PrintTextW(L"[사업자번호] 305-82-03140      대표자 : 노용재\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
//    PrintTextW(L"[주소] 35242 대전광역시 서구 둔산로 100(둔산동) ☎ 042-270-2342\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
//    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);




    QString mon_sun_format = "ddd";
    QString date_format = "yyyy년 MM월 dd일";
    QString time_format = "hh:mm";
    QString mon_sun_str = QDateTime::currentDateTime().toString(mon_sun_format);


    QString date_str = QDateTime::currentDateTime().toString(date_format) + "(" + mon_sun_str + ")";
    QString time_str = " " + date_str +  " " + QDateTime::currentDateTime().toString(time_format) + "옥산(하) 휴게소 점\n";
    PrintTextW(time_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    // 3 + 4 + 10 + 3
    PrintTextW(L"        상 품 명                  금  액  \n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    for(int i=0; i<menu_list.size(); i++){
        //for(int j=0; j<menu_list[i].quantity; j++){
        QString menuname = "";

//        menuname+=menu_list[i].menu;

        if(menu_list[i].optionSyrup == 0) menuname+="(시럽없음)";
        else if(menu_list[i].optionSyrup == 2) menuname+="(시럽보통)";
        else if(menu_list[i].optionSyrup == 3) menuname+="(시럽많이)";


            int menu_length = CountLength(menu_list[i].menu);//menu_list[i].menu.length();
//            qDebug()<<menu_length;
            int space_length1 = (26-menu_length)/2;//10-menu_length;
            int space_length2 = 26-menu_length-space_length1;

            QString detail_str;
            for(int i=0; i<space_length1; i++){
                detail_str += " ";
            }
            detail_str += menu_list[i].menu;



            for(int i=0; i<space_length2; i++){
                detail_str += " ";
            }
            for(int i=0; i<9; i++){
                detail_str += " ";
            }
            if(menu_list[i].menu.indexOf("+") != -1){
                detail_str += " ";
            }
            QString price_str;
            price_str.sprintf("%d", menu_list[i].price);
            if(menu_list[i].price > 999){
                int price_length = price_str.length();
                price_str.insert(price_length-3, ",");
            }
            detail_str += price_str + "\n";




            menu_length = CountLength(menuname);
            space_length1 = (26-menu_length)/2;//10-menu_length;
            space_length2 = 26-menu_length-space_length1;
            QString option_str;
            for(int i=0; i<space_length1; i++){
                option_str += " ";
            }
            option_str+=menuname;
            for(int i=0; i<space_length2; i++){
                option_str += " ";
            }
            for(int i=0; i<9; i++){
                option_str += " ";
            }
            if(menuname.indexOf("+") != -1){
                option_str += " ";
            }


            detail_str += option_str + "\n";



            PrintTextW(detail_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
        //}
    }
    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString price_str1;
    QString price_str2;
    QString price_str3;
    int price3 = price;
    int price1 = price*10/11;
    int price2 = price3-price1;
    price_str1.sprintf("%d", price1);
    price_str2.sprintf("%d", price2);
    price_str3.sprintf("%d", price3);
    if(price1 > 999){
        int price_length1 = price_str1.length();
        price_str1.insert(price_length1-3, ",");
    }
    if(price2 > 999){
        int price_length2 = price_str2.length();
        price_str2.insert(price_length2-3, ",");
    }
    if(price3 > 999){
        int price_length3 = price_str3.length();
        price_str3.insert(price_length3-3, ",");
    }
    QString price_tot_str1;
    QString price_tot_str2;
    QString price_tot_str3;

    price_tot_str1 = "       공급가금액";
    for(int i=0; i<18; i++){
        price_tot_str1 += " ";
    }
    if(price1 < 999)
        price_tot_str1 += "  ";
    price_tot_str1 += price_str1 + "\n";


    price_tot_str2 = "       부  가  세";
    for(int i=0; i<18; i++){
        price_tot_str2 += " ";
    }
    if(price2 < 999)
        price_tot_str2 += "  ";
    price_tot_str2 += price_str2 + "\n";


    price_tot_str3 = "       합계  금액";
    for(int i=0; i<18; i++){
        price_tot_str3 += " ";
    }
    if(price3 < 999)
        price_tot_str3 += "  ";
    price_tot_str3 += price_str3 + "\n";

    PrintTextW(price_tot_str1.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(price_tot_str2.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(price_tot_str3.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
//    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"** 신용카드 결제 **\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT |BXL_FT_BOLD, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
//    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString card_comp_str;
    card_comp_str = "  카 드 사 명 : ";
    card_comp_str += card_comp + "\n";
    PrintTextW(card_comp_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString card_num_str;
    card_num_str = "  카 드 번 호 : ";
    card_num_str += card_num + "\n";
    PrintTextW(card_num_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString appr_date_str;
    appr_date_str = "  승 인 일 자 : ";
    appr_date_str += tran_date + "\n";
    PrintTextW(appr_date_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString payment_month_str;
    payment_month_str = "  할 부 기 간 : 일시불\n";
    PrintTextW(payment_month_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString appr_num_str;
    appr_num_str = "  승 인 번 호 : ";
    appr_num_str += approve_num + "\n";
    PrintTextW(appr_num_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString appr_price_str;
    appr_price_str = "  승 인 금 액 : ";
    appr_price_str += price_str3 + "\n";
    PrintTextW(appr_price_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"================================================\n\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

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
    PrintTextW(L"※ 주문 오류 발생 시, 카카오톡채널 @보바로보코리아로 메시지 주시면, 영업시간 이내 확인하여 도와드리도록 하겠습니다.\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    PrintTextW(L"\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    //PrintBarcode((char*)("12345678"), BXL_BCS_ITF, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_BELOW);
    //PrintBarcode((char*)("11111111"), BXL_BCS_ITF, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_BELOW);
//    PrintBarcode((char*)("197711011"), BXL_BCS_ITF, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_BELOW);
//    PrintBarcode((char*)("1977110112"), BXL_BCS_ITF, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_BELOW);
//    PrintBarcode((char*)("19771101123"), BXL_BCS_ITF, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_BELOW);
//    PrintBarcode((char*)("197711011234"), BXL_BCS_ITF, 100, 2, BXL_ALIGNMENT_CENTER, BXL_BC_TEXT_BELOW);



//    OpenDrawer(BXL_CASHDRAWER_PIN5);
    CutPaper();

//    LineFeed(2);

    PaperEject(BXL_EJT_HOLD);

    if(TransactionEnd(TRUE, 3000 /* 3 seconds */) != BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter]  RBPrint Fail: " + approve_num);
        // failed to read a response from the printer after sending the print-data.
//        MessageBox(_T("TransactionEnd failed."), NULL, MB_OK|MB_ICONERROR);
    }else{
        rblog->AddLogLine("[RBPrinter]  RBPrint Success: " + approve_num);

    }

    return 0;
}

int RBPrinter::RBPrintCancelReceipt(int mode,  QVector<ST_ORDER_INFO> menu_list, int price, QString card_comp, QString card_num,
                              QString approve_num, QString tran_date){
    if(TransactionStart()!=BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter]  CancelReceiptPrint transaction Fail");
    }

    if(InitializePrinter()!=BXL_SUCCESS){

        rblog->AddLogLine("[RBPrinter]  CancelReceiptPrint initialize Fail");
    }

    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT |BXL_FT_BOLD | BXL_FT_UNDERLINE, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);


    PrintTextW(L"대보디앤에스(주)옥산(하)휴게소\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"[사업자번호] 301-81-23531      \n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"[주소] 충청북도 청주시 흥덕구 옥산면 경부고속도로 309  ☎ 043-260-1053\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    if(mode == 0)
        PrintTextW(L" [재발행 영수증] \n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);
    else
        PrintTextW(L" [환불 영수증] \n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);


    PrintTextW(L"\n\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    QString mon_sun_format = "ddd";
    QString date_format = "yyyy년 MM월 dd일";
    QString time_format = "hh:mm";
    QString mon_sun_str = QDateTime::currentDateTime().toString(mon_sun_format);


    QString date_str = QDateTime::currentDateTime().toString(date_format) + "(" + mon_sun_str + ")";
    QString time_str = " " + date_str +  " " + QDateTime::currentDateTime().toString(time_format) +"옥산(하) 휴게소 점\n";
    PrintTextW(time_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    // 3 + 4 + 10 + 3
    PrintTextW(L"        상 품 명                  금  액  \n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    for(int i=0; i<menu_list.size(); i++){
        //for(int j=0; j<menu_list[i].quantity; j++){
            int menu_length = CountLength(menu_list[i].menu);//menu_list[i].menu.length();
//            qDebug()<<menu_length;
            int space_length1 = (26-menu_length)/2;//10-menu_length;
            int space_length2 = 26-menu_length-space_length1;

            QString detail_str;
            for(int i=0; i<space_length1; i++){
                detail_str += " ";
            }

            QStringList list = menu_list[i].menu.split("\n");
            detail_str += list.last();
            for(int i=0; i<space_length2; i++){
                detail_str += " ";
            }
            for(int i=0; i<9; i++){
                detail_str += " ";
            }
            if(menu_list[i].menu.indexOf("+") != -1){
                detail_str += " ";
            }
            QString price_str;


            int pricetot = (mode==0)?menu_list[i].price:-menu_list[i].price;
            price_str.sprintf("%d", pricetot);
            if(menu_list[i].price > 999){
                int price_length = price_str.length();
                price_str.insert(price_length-3, ",");
            }
            detail_str += price_str + "\n";
            PrintTextW(detail_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
        //}
    }
    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString price_str1;
    QString price_str2;
    QString price_str3;

    int price1 = (mode==0)?price*10/11:-price*10/11;
    int price3 = (mode==0)?price:-price;
    int price2 = (mode==0)?(price3-price1):-(price3-price1);
    price_str1.sprintf("%d", price1);
    price_str2.sprintf("%d", price2);
    price_str3.sprintf("%d", price3);
    if(abs(price1) > 999){
        int price_length1 = price_str1.length();
        price_str1.insert(price_length1-3, ",");
    }
    if(abs(price2) > 999){
        int price_length2 = price_str2.length();
        price_str2.insert(price_length2-3, ",");
    }
    if(abs(price3) > 999){
        int price_length3 = price_str3.length();
        price_str3.insert(price_length3-3, ",");
    }
    QString price_tot_str1;
    QString price_tot_str2;
    QString price_tot_str3;

    price_tot_str1 = "       공급가금액";
    for(int i=0; i<18; i++){
        price_tot_str1 += " ";
    }
    if(price1 < 999)
        price_tot_str1 += "  ";
    price_tot_str1 += price_str1 + "\n";


    price_tot_str2 = "       부  가  세";
    for(int i=0; i<18; i++){
        price_tot_str2 += " ";
    }
    if(price2 < 999)
        price_tot_str2 += "  ";
    price_tot_str2 += price_str2 + "\n";


    price_tot_str3 = "       합계  금액";
    for(int i=0; i<18; i++){
        price_tot_str3 += " ";
    }
    if(price3 < 999)
        price_tot_str3 += "  ";
    price_tot_str3 += price_str3 + "\n";

    PrintTextW(price_tot_str1.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(price_tot_str2.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(price_tot_str3.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
//    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    if(mode == 0)
        PrintTextW(L"** 신용카드 결제 **\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT |BXL_FT_BOLD, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    else
        PrintTextW(L"** 신용카드 결제 취소 **\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT |BXL_FT_BOLD, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

//    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT | BXL_FT_UNDERLINE, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString card_comp_str;
    card_comp_str = "  카 드 사 명 : ";
    card_comp_str += card_comp + "\n";
    PrintTextW(card_comp_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString card_num_str;
    card_num_str = "  카 드 번 호 : ";
    card_num_str += card_num + "\n";
    PrintTextW(card_num_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString appr_date_str;
    appr_date_str = "  승 인 일 자 : ";
    appr_date_str += tran_date + "\n";
    PrintTextW(appr_date_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString payment_month_str;
    payment_month_str = "  할 부 기 간 : 일시불\n";
    PrintTextW(payment_month_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString appr_num_str;
    appr_num_str = "  승 인 번 호 : ";
    appr_num_str += approve_num + "\n";
    PrintTextW(appr_num_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString appr_price_str;
    appr_price_str = "  승 인 금 액 : ";
    appr_price_str += price_str3 + "\n";
    PrintTextW(appr_price_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"================================================\n\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    if(mode == 0){
        QString pin_str = "주문번호 : " + approve_num.right(5);
        PrintTextW(pin_str.toStdWString().data(), BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);
        PrintTextW(L"\n\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

        char barcode_char[20];
        sprintf(barcode_char, "a%sz\0", approve_num.right(5).toStdString().data());

        PrintQRCode(barcode_char, BXL_QRCODE_MODEL1,100,BXL_QRCODE_ECC_LEVEL_M,BXL_ALIGNMENT_CENTER);

        PrintTextW(L"\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


        PrintTextW(L"※ 픽업시 영수증의 바코드가 필요하니 영수증을 버리지 않고 꼭 소지해주세요!\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
        PrintTextW(L"※ 오른쪽 주문 완료 현황판에 주문번호 확인 후 바코드 리더기에 영수증의 바코드를 찍으면 음료가 나옵니다.\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
        PrintTextW(L"※ 주문 오류 발생 시, 카카오톡채널 @보바로보코리아로 메시지 주시면, 영업시간 이내 확인하여 도와드리도록 하겠습니다.\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


        PrintTextW(L"\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    }else{
        PrintTextW(L"\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    }





//    OpenDrawer(BXL_CASHDRAWER_PIN5);
    CutPaper();

//    LineFeed(2);

    PaperEject(BXL_EJT_HOLD);

    if(TransactionEnd(TRUE, 3000 /* 3 seconds */) != BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter] RBPrintCancel Fail : " + approve_num);
        // failed to read a response from the printer after sending the print-data.
//        MessageBox(_T("TransactionEnd failed."), NULL, MB_OK|MB_ICONERROR);
    }else{
        rblog->AddLogLine("[RBPrinter] RBPrintCancel Success : " + approve_num);

    }


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

int RBPrinter::RBPrintDayReport(SaleReport _report){

    // Enters 'Transaction' mode.
    if(TransactionStart()!=BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter]  Print transaction Fail");
    }

    if(InitializePrinter()!=BXL_SUCCESS){

        rblog->AddLogLine("[RBPrinter]  Print initialize Fail");
    }

    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT |BXL_FT_BOLD | BXL_FT_UNDERLINE, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);

    PrintTextW(L" *** 영업 일보 *** \n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);
    PrintTextW(L"\n\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"사업자No : 301-81-23531\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"사업장명 : 옥산(하)휴게소\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"매장명   : 옥하 보바로보 <0001-0081>\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString sale_date_str = "영업일자 : ";
    QString print_date_str = "인쇄일자 : ";

    sale_date_str += _report.Day.toString("yyyy년 MM월 dd일") + "\n";
    print_date_str += QDateTime().currentDateTime().toString("yyyy년 MM년 dd일 HH:mm:ss") + "\n";

    PrintTextW(sale_date_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(print_date_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"\n\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    QString temp_line;
    QString temp_price;
    int price;

    price = _report.total_sale_amt+_report.refund_sale_amt;
    temp_price.sprintf("%d",price);
    if(price > 999){
        temp_price.insert(temp_price.length()-3,",");
    }
    temp_line = "총판매액 :              " + temp_price + "\n";
    PrintTextW(temp_line.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    price = _report.refund_sale_amt;
    temp_price.sprintf("%d",price);
    if(price > 999){
        temp_price.insert(temp_price.length()-3,",");
    }
    temp_line = "반품판매 :              -" + temp_price + "\n";
    PrintTextW(temp_line.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    price = _report.total_sale_amt;
    temp_price.sprintf("%d",price);
    if(price > 999){
        temp_price.insert(temp_price.length()-3,",");
    }
    temp_line = "실매출액 :              " + temp_price + "\n";
    PrintTextW(temp_line.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    price = _report.total_sale_amt;
    temp_price.sprintf("%d",price);
    if(price > 999){
        temp_price.insert(temp_price.length()-3,",");
    }
    temp_line = "카드매출 :              " + temp_price + "\n";
    PrintTextW(temp_line.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    price = 0;
    temp_price.sprintf("%d",price);
    if(price > 999){
        temp_price.insert(temp_price.length()-3,",");
    }
    temp_line = "현금매출 :              " + temp_price + "\n";
    PrintTextW(temp_line.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    price = _report.total_sale_cnt;
    temp_price.sprintf("%d",price);
    temp_line = "객    수 :              " + temp_price + "\n";
    PrintTextW(temp_line.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    if(_report.total_sale_amt == 0){
        price = 0;
    }else{
        price = _report.total_sale_amt/_report.total_sale_cnt;
    }
    temp_price.sprintf("%d",price);
    if(price > 999){
        temp_price.insert(temp_price.length()-3,",");
    }
    temp_line = "객 단 가 :              " + temp_price + "\n";
    PrintTextW(temp_line.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"      상 품 명         수  량         금  액  \n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    int total_sale_num = 0;
    int total_sale_price = 0;
    for(int i=0; i<_report.Menu.size(); i++){
        int menu_length = CountLength(_report.Menu[i].menu_name);
        int space_length1 = (22-menu_length)/2;
        int space_length2 = 22-menu_length-space_length1;

        QString detail_str;
        for(int i=0; i<space_length1; i++){
            detail_str += " ";
        }

        detail_str += _report.Menu[i].menu_name;

        for(int i=0; i<space_length2; i++){
            detail_str += " ";
        }

        QString num_str;
        num_str.sprintf("(%d건)",_report.Menu[i].num);
        total_sale_num += _report.Menu[i].num;

        menu_length = CountLength(num_str);
        space_length1 = (11-menu_length)/2;
        space_length2 = 11-menu_length-space_length1;

        for(int i=0; i<space_length1; i++){
            detail_str += " ";
        }

        detail_str += num_str;

        for(int i=0; i<space_length2; i++){
            detail_str += " ";
        }

        for(int i=0; i<9; i++){
            detail_str += " ";
        }
        QString price_str;
        int pricetot = _report.Menu[i].amt;
        price_str.sprintf("%d", pricetot);
        total_sale_price += pricetot;
        if(pricetot > 999){
            int price_length = price_str.length();
            price_str.insert(price_length-3, ",");
        }
        detail_str += price_str + "\n";
        PrintTextW(detail_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    }
    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    int menu_length = CountLength("총 합계");
    int space_length1 = (22-menu_length)/2;
    int space_length2 = 22-menu_length-space_length1;

    QString detail_str;
    for(int i=0; i<space_length1; i++){
        detail_str += " ";
    }

    detail_str += "총 합계";

    for(int i=0; i<space_length2; i++){
        detail_str += " ";
    }

    QString num_str;
    num_str.sprintf("(%d건)",total_sale_num);

    menu_length = CountLength(num_str);
    space_length1 = (11-menu_length)/2;
    space_length2 = 11-menu_length-space_length1;

    for(int i=0; i<space_length1; i++){
        detail_str += " ";
    }

    detail_str += num_str;

    for(int i=0; i<space_length2; i++){
        detail_str += " ";
    }

    for(int i=0; i<9; i++){
        detail_str += " ";
    }
    QString price_str;
    int pricetot = total_sale_price;
    price_str.sprintf("%d", pricetot);
    if(pricetot > 999){
        int price_length = price_str.length();
        price_str.insert(price_length-3, ",");
    }
    detail_str += price_str + "\n";
    PrintTextW(detail_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    CutPaper();

    PaperEject(BXL_EJT_HOLD);

    if(TransactionEnd(TRUE, 3000 /* 3 seconds */) != BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter]  RBPrintDayReport Fail");
    }else{
        rblog->AddLogLine("[RBPrinter]  RBPrintDayReport Success");
    }

    return 0;
}

int RBPrinter::RBPrintCardReport(SaleReport _report){

    // Enters 'Transaction' mode.
    if(TransactionStart()!=BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter]  Print transaction Fail");
    }

    if(InitializePrinter()!=BXL_SUCCESS){

        rblog->AddLogLine("[RBPrinter]  Print initialize Fail");
    }

    PrintTextW(L"\n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT |BXL_FT_BOLD | BXL_FT_UNDERLINE, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);

    PrintTextW(L" * 매입사별 매출현황 * \n", BXL_ALIGNMENT_CENTER, BXL_FT_DEFAULT, BXL_TS_1WIDTH | BXL_TS_1HEIGHT);
    PrintTextW(L"\n\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"사업자No : 301-81-23531\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"사업장명 : 옥산(하)휴게소\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"매장명   : 옥하 보바로보 <0001-0081>\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    QString sale_date_str = "영업일자 : ";
    QString print_date_str = "인쇄일자 : ";

    sale_date_str += _report.Day.toString("yyyy년 MM월 dd일") + "\n";
    print_date_str += QDateTime().currentDateTime().toString("yyyy년 MM년 dd일 HH:mm:ss") + "\n";

    PrintTextW(sale_date_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(print_date_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    PrintTextW(L"\n\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"   매입사명       구분(건수)      승인금액    \n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    for(int i=0; i<_report.Card.size(); i++){
        int menu_length = CountLength(_report.Card[i].card_name);
        int space_length1 = (20-menu_length)/2;
        int space_length2 = 20-menu_length-space_length1;

        QString detail_str;
        for(int i=0; i<space_length1; i++){
            detail_str += " ";
        }

        detail_str += _report.Card[i].card_name;

        for(int i=0; i<space_length2; i++){
            detail_str += " ";
        }

        QString num_str;
        QString temp_str;
        temp_str.sprintf("(%d건)",_report.Card[i].num);
        num_str = _report.Card[i].sale_gb + temp_str;

        menu_length = CountLength(num_str);
        space_length1 = (10-menu_length)/2;
        space_length2 = 10-menu_length-space_length1;

        for(int i=0; i<space_length1; i++){
            detail_str += " ";
        }

        detail_str += num_str;

        for(int i=0; i<space_length2; i++){
            detail_str += " ";
        }

        for(int i=0; i<9; i++){
            detail_str += " ";
        }
        QString price_str;
        int pricetot = _report.Card[i].amt;
        price_str.sprintf("%d", pricetot);
        if(pricetot > 999){
            int price_length = price_str.length();
            price_str.insert(price_length-3, ",");
        }
        if(_report.Card[i].sale_gb == "취소"){
            detail_str += "-" + price_str + "\n";
        }else{
            detail_str += price_str + "\n";
        }
        PrintTextW(detail_str.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);
    }
    PrintTextW(L"------------------------------------------------\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    QString temp_line;
    QString temp_price;
    int price;

    price = _report.total_sale_amt;
    temp_price.sprintf("%d",price);
    if(price > 999){
        temp_price.insert(temp_price.length()-3,",");
    }
    temp_line = "            합계 :           " + temp_price + "\n";
    PrintTextW(temp_line.toStdWString().data(), BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);


    PrintTextW(L"================================================\n", BXL_ALIGNMENT_LEFT, BXL_FT_DEFAULT, BXL_TS_0WIDTH | BXL_TS_0HEIGHT);

    CutPaper();

    PaperEject(BXL_EJT_HOLD);

    if(TransactionEnd(TRUE, 3000 /* 3 seconds */) != BXL_SUCCESS){
        rblog->AddLogLine("[RBPrinter]  RBPrintCardReport Fail");
    }else{

        rblog->AddLogLine("[RBPrinter]  RBPrintCardReport Success");
    }

    return 0;
}
