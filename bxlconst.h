
// PAGE MODE
#define BXL_PRINTER_PD_0			0
#define BXL_PRINTER_PD_LEFT90		1
#define BXL_PRINTER_PD_180			2
#define BXL_PRINTER_PD_RIGHT90		3

#define BXL_PRINTER_PAGEMODE_OUT	0
#define BXL_PRINTER_PAGEMODE_IN		1

// CASH DRAWER
#define BXL_CASHDRAWER_PIN2    0
#define BXL_CASHDRAWER_PIN5    1

// BCD TEXT ENCODING
#define BXL_TEXT_ENCODE_PC437			437		// 437 (USA, Standard Europe)
#define BXL_TEXT_ENCODE_PC866			866		// 866 (Cyrillic #2)
#define BXL_TEXT_ENCODE_PC852			852		// 852 (Latin 2)
#define BXL_TEXT_ENCODE_PC857			857		// 857 (Turkish)
#define BXL_TEXT_ENCODE_PC850			850		// 850 (Multilingual)
#define BXL_TEXT_ENCODE_PC860			860		// 860 (Portuguese)
#define BXL_TEXT_ENCODE_PC863			863		// 863 (Canadian-French)
#define BXL_TEXT_ENCODE_PC865			865		// 865 (Nordic)
#define BXL_TEXT_ENCODE_PC1250			1250	// 1250 (Czech)
#define BXL_TEXT_ENCODE_WPC1251			1251	// 1251 (Cyrillic)
#define BXL_TEXT_ENCODE_WPC1252			1252	// 1252 (Latin I)
#define BXL_TEXT_ENCODE_PC866			866		// 866 (Cyrillic #2)
#define BXL_TEXT_ENCODE_PC858			858		// 858 (Euro)
#define BXL_TEXT_ENCODE_PC862			862		// 862 (Hebrew DOS code)
#define BXL_TEXT_ENCODE_WPC1254			1254	// 1254 (Turkish)
#define BXL_TEXT_ENCODE_WPC1257			1257	// 1257 (Baltic)
#define BXL_TEXT_ENCODE_PC775			775		// 775 (Baltic)
#define BXL_TEXT_ENCODE_PC737			737		// 737 (Greek)
#define BXL_TEXT_ENCODE_WPC1253			1253	// 1253 (Greek)
#define BXL_TEXT_ENCODE_PC857			857		// 857 (Turkish)
#define BXL_TEXT_ENCODE_WPC1255			1255	// 1255 (Hebrew New Code)
#define BXL_TEXT_ENCODE_PC855			855		// 855 (Cyrillic)
#define BXL_TEXT_ENCODE_PC928			928		// 928 (Greek)
#define BXL_TEXT_ENCODE_PC1258			1258	// 1258 (Vietnam)
#define BXL_TEXT_ENCODE_TCVN			49		// TCVN-3 (Vietnamese1)
#define BXL_TEXT_ENCODE_TCVN_CAPITAL	50		// TCVN-3 (Vietnamese2)

//////////////////////////////////////////////////////////////////
//Result Code 
#define BXL_SUCCESS					0
#define BXL_READBUFFER_EMPTY		-1
#define BXL_CONNECT_FAIL			-100
#define BXL_NOT_OPENED				-101
#define BXL_NOT_SUPPORT				-107
#define BXL_INVALID_PARAM			-108
#define BXL_BUFFER_ERROR			-109
#define BXL_NO_PRINT_DATA			-110
#define BXL_COMPLETE_ERROR			-111
#define BXL_NO_TRANSACTION_START	-112
#define BXL_TEXT_ENCODING_ERROR		-120
#define BXL_PAGE_MODE_ALREADY_IN	-130
#define BXL_NOT_IN_PAGE_MODE		-131
#define BXL_REGISTRY_ERROR			-200
#define BXL_WRITE_ERROR				-300
#define BXL_READ_ERROR				-301
#define BXL_BMP_LOAD_ERROR			-400
#define BXL_BMP_BUFFER_SIZE_ERROR	-401
#define BXL_BC_DATA_ERROR			-500
#define BXL_BC_NOT_SUPPORT			-501

// Printer Status flag
#define BXL_STS_NORMAL					0
#define BXL_STS_PAPEREMPTY				1
#define BXL_STS_COVEROPEN				2
#define BXL_STS_PAPER_NEAR_END			4
#define BXL_STS_AUTOCUTTER_ERROR		8
//#define BXL_STS_CASHDRAWER_OPEN		16
#define BXL_STS_CASHDRAWER_HIGH			16
#define BXL_STS_ERROR					32
#define BXL_STS_NOT_OPEN				64
#define BXL_STS_BATTERY_LOW				128
#define BXL_STS_PAPER_TO_BE_TAKEN		256
#define BXL_STS_CASHDRAWER_LOW			512

//Presenter Status flag
#define BXL_PRT_STS_NORMAL				0
#define BXL_PRT_STS_PAPER_NEAR_END		1
#define BXL_PRT_STS_PAPEREMPTY			4
#define BXL_PRT_STS_PAPER_IN			8
#define BXL_PRT_STS_PAPER_JAM			128

//Alignment
#define BXL_ALIGNMENT_DEFAULT	-1
#define BXL_ALIGNMENT_LEFT		0
#define BXL_ALIGNMENT_CENTER	1
#define BXL_ALIGNMENT_RIGHT		2

//Text Attribute
#define BXL_FT_DEFAULT			0
#define BXL_FT_FONTB			1
#define BXL_FT_FONTC			16 
#define BXL_FT_BOLD				2
#define BXL_FT_UNDERLINE		4		
#define BXL_FT_UNDERTHICK		6
#define BXL_FT_REVERSE			8
#define BXL_FT_UPSIDEDOWN		10
#define BXL_FT_RED_COLOR		64

//Text Size Attribute
#define BXL_TS_0WIDTH			0
#define BXL_TS_1WIDTH			16
#define BXL_TS_2WIDTH			32
#define BXL_TS_3WIDTH			48
#define BXL_TS_4WIDTH			64
#define BXL_TS_5WIDTH			80
#define BXL_TS_6WIDTH			96
#define BXL_TS_7WIDTH			112

#define BXL_TS_0HEIGHT			0	
#define BXL_TS_1HEIGHT			1
#define BXL_TS_2HEIGHT			2
#define BXL_TS_3HEIGHT			3
#define BXL_TS_4HEIGHT			4
#define BXL_TS_5HEIGHT			5
#define BXL_TS_6HEIGHT			6
#define BXL_TS_7HEIGHT			7

//Width Full
#define BXL_WIDTH_FULL	-1
#define BXL_WIDTH_NONE	-2

// QR CODE MODEL
#define BXL_QRCODE_MODEL1			49
#define BXL_QRCODE_MODEL2			50
// QR CODE ECC LEVEL
#define BXL_QRCODE_ECC_LEVEL_L		48
#define BXL_QRCODE_ECC_LEVEL_M		49
#define BXL_QRCODE_ECC_LEVEL_Q		50
#define BXL_QRCODE_ECC_LEVEL_H		51
// PDF417 TYPE
#define BXL_PDF417_TYPE1			49
#define BXL_PDF417_TYPE2			50
// PDF417 ECC LEVEL
#define BXL_PDF417_ECC_LEVEL_0		48
#define BXL_PDF417_ECC_LEVEL_1		49
#define BXL_PDF417_ECC_LEVEL_2		50
#define BXL_PDF417_ECC_LEVEL_3		51
#define BXL_PDF417_ECC_LEVEL_4		52
#define BXL_PDF417_ECC_LEVEL_5		53
#define BXL_PDF417_ECC_LEVEL_6		54
#define BXL_PDF417_ECC_LEVEL_7		55
#define BXL_PDF417_ECC_LEVEL_8		56

// GS1 DATABAR
#define BXL_GS1DATABAR_STACKED								0
#define BXL_GS1DATABAR_STACKED_OMNIDIRECTIONAL				1
// COMPOSITE SYMBOLOGY (LINEAR)
#define BXL_COMPOSITE_LINE_EAN8									65
#define BXL_COMPOSITE_LINE_EAN13								66
#define BXL_COMPOSITE_LINE_UPCA									67
#define BXL_COMPOSITE_LINE_UPCE									69
#define BXL_COMPOSITE_LINE_GS1DATABAR_OMNIDIRECTIONAL			70
#define BXL_COMPOSITE_LINE_GS1DATABAR_TRUNCATED					71
#define BXL_COMPOSITE_LINE_GS1DATABAR_STACKED					72
#define BXL_COMPOSITE_LINE_GS1DATABAR_STACKED_OMNIDIRECTIONAL	73
#define BXL_COMPOSITE_LINE_GS1DATABAR_LIMITED					74
#define BXL_COMPOSITE_LINE_GS1DATABAR_EXPANDED					75
#define BXL_COMPOSITE_LINE_GS1_128								77
// COMPOSITE SYMBOLOGY (2D)
#define BXL_COMPOSITE_2D_AUTO									65
#define BXL_COMPOSITE_2D_CC_C									66

//BARCODE
#define BXL_BCS_PDF417													200
#define BXL_BCS_QRCODE_MODEL2											202 
#define BXL_BCS_QRCODE_MODEL1											203 
#define BXL_BCS_DATAMATRIX												204 
#define BXL_BCS_MAXICODE_MODE2											205 
#define BXL_BCS_MAXICODE_MODE3											206 
#define BXL_BCS_MAXICODE_MODE4											207 
#define BXL_BCS_2D_GS1DATABAR_STACKED									208
#define BXL_BCS_2D_GS1DATABAR_STACKED_OMNIDIRECTIONAL                   209
#define BXL_BCS_COMPOSITE_SYMBOLE_EAN8                                  210
#define BXL_BCS_COMPOSITE_SYMBOLE_EAN13                                 211
#define BXL_BCS_COMPOSITE_SYMBOLE_UPCA                                  212
#define BXL_BCS_COMPOSITE_SYMBOLE_UPCE                                  213
#define BXL_BCS_COMPOSITE_SYMBOLE_GS1DATABAR_OMNIDIRECTIONAL            214
#define BXL_BCS_COMPOSITE_SYMBOLE_GS1DATABAR_TRUNCATED                  215
#define BXL_BCS_COMPOSITE_SYMBOLE_GS1DATABAR_STACKED                    216
#define BXL_BCS_COMPOSITE_SYMBOLE_GS1DATABAR_STACKED_OMNIDIRECTIONAL    217
#define BXL_BCS_COMPOSITE_SYMBOLE_GS1DATABAR_LIMITED                    218
#define BXL_BCS_COMPOSITE_SYMBOLE_GS1DATABAR_EXPANDED                   219
#define BXL_BCS_COMPOSITE_SYMBOLE_GS1_128                               220

#define BXL_BCS_UPCA							101
#define BXL_BCS_UPCE							102
#define BXL_BCS_EAN8							103
#define BXL_BCS_EAN13							104
#define BXL_BCS_JAN8							105
#define BXL_BCS_JAN13							106
#define BXL_BCS_ITF								107
#define BXL_BCS_CODABAR							108
#define BXL_BCS_CODE39							109
#define BXL_BCS_CODE93							110
#define BXL_BCS_CODE128							111
#define BXL_BCS_1D_GS1_128						112
#define BXL_BCS_1D_GS1DATABAR_OMNIDIRECTION		113
#define BXL_BCS_1D_GS1DATABAR_TRUNCATED			114
#define BXL_BCS_1D_GS1DATABAR_LIMITED			115

//Barcode HRI position
#define BXL_BC_TEXT_NONE		0
#define BXL_BC_TEXT_ABOVE		1
#define BXL_BC_TEXT_BELOW		2

// Character Set
#define BXL_CS_PC437			0	// (USA, Standard Europe)
#define BXL_CS_KATAKANA			1	// Katakana
#define BXL_CS_PC850			2	// 850 (Multilingual)
#define BXL_CS_PC860			3	// 860 (Portuguese)
#define BXL_CS_PC863			4	// 863 (Canadian-French)
#define BXL_CS_PC865			5	// 865 (Nordic)
#define BXL_CS_WPC1252			16	// 1252 (Latin I)
#define BXL_CS_PC866			17	// 866 (Cyrillic #2)
#define BXL_CS_PC852			18	// 852 (Latin 2)
#define BXL_CS_PC858			19	// 858 (Euro)
#define BXL_CS_PC862			21	// 862 (Hebrew DOS code)
#define BXL_CS_PC864			22	// NOT Supported / 864 (Arabic)
#define BXL_CS_THAI42			23	// THAI42
#define BXL_CS_WPC1253			24	// 1253 (Greek)
#define BXL_CS_WPC1254			25	// 1254 (Turkish)
#define BXL_CS_WPC1257			26	// 1257 (Baltic)
#define BXL_CS_FARSI			27	// NOT Supported / FARSI
#define BXL_CS_WPC1251			28	// 1251 (Cyrillic)
#define BXL_CS_PC737			29	// 737 (Greek)
#define BXL_CS_PC775			30	// 775 (Baltic)
#define BXL_CS_THAI14			31	// THAI14
#define BXL_CS_WPC1255			33	// 1255 (Hebrew New Code)
#define BXL_CS_THAI11			34	// THAI11
#define BXL_CS_THAI18			35	// THAI18
#define BXL_CS_PC855			36	// 855 (Cyrillic)
#define BXL_CS_PC857			37	// 857 (Turkish)
#define BXL_CS_PC928			38	// 928 (Greek)
#define BXL_CS_THAI16			39	// THAI16
#define BXL_CS_WPC1256			40	// NOT Supported / 1256 (Arabic)
#define BXL_CS_PC1258			41	// 1258 (Vietnam)
#define BXL_CS_KHMER			42	// NOT Supported / KHMER(Cambodia)
#define BXL_CS_PC1250			47	// 1250 (Czech)
#define BXL_CS_LATIN9			48	// Latin 9
#define BXL_CS_TCVN				49	// TCVN-3 (Vietnamese1)
#define BXL_CS_TCVN_CAPITAL		50	// TCVN-3 (Vietnamese2)
#define BXL_CS_VISCII			51	// VISCII (Vietnamese)
#define BXL_CS_USER				255
#define BXL_CS_UTF8				65001	// UTF-8
#define BXL_CS_KS5601			949		// KOREAN
#define BXL_CS_BIG5				950		// CHINESE (BIG5)
#define BXL_CS_GB2312			936		// Simplified CHINESE (GB2312)
#define BXL_CS_SHIFT_JIS		932		// JAPAN (Shift JIS)

// International CharacterSet
#define BXL_ICS_USA			0
#define BXL_ICS_FRANCE		1
#define BXL_ICS_GERMANY		2
#define BXL_ICS_UK			3
#define BXL_ICS_DENMARK1	4
#define BXL_ICS_SWEDEN		5
#define BXL_ICS_ITALY		6
#define BXL_ICS_SPAIN		7
#define BXL_ICS_JAPAN		8
#define BXL_ICS_NORWAY		9
#define BXL_ICS_DENMARK2	10	
#define BXL_ICS_SPAIN2		11	
#define BXL_ICS_LATIN		12	
#define BXL_ICS_KOREA		13	
#define BXL_ICS_SLOVENIA    14
#define BXL_ICS_CHINA       15

// Interface Type
#define ISerial		0
#define IParallel	1
#define IUsb		2
#define ILan		3
#define IWLan		4
#define IBluetooth	5

// Sereal Flow Control
#define BXL_SERIAL_DTR_DSR	0
#define BXL_SERIAL_XON_XOFF	1
#define BXL_SERIAL_NONE		2

// Eject Options
#define BXL_EJT_NONE		0
#define BXL_EJT_HOLD		1
