#ifdef BXLPAPI_EXPORTS
#define BXLPAPIP __declspec(dllexport)
#else
#define BXLPAPI __declspec(dllimport)
#endif

#include <winnls.h>
//#include <windows.h>
#include "winbase.h"

typedef int (CALLBACK *fnStatusCallbackFunc)(int nStatus);

BXLPAPI long __stdcall PrinterOpen(int nInterface, 
									   LPCTSTR szPortName = "", 
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
