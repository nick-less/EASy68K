//---------------------------------------------------------------------------

#ifndef simIOuH
#define simIOuH
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <MPlayer.hpp>
#include <Graphics.hpp>

//#include <vcl\Clipbrd.hpp>
#include "def.h"
#include "net.h"
#include <Dialogs.hpp>
#define HANDLE void *
#define COMMTIMEOUTS int
//---------------------------------------------------------------------------
class TsimIO : public TForm
{
__published:	// IDE-managed Components
        TTimer *prompt;
        TOpenDialog *OpenDialogIO;
        TSaveDialog *SaveDialogIO;
        void  promptTimer(TObject *Sender);
        void  FormKeyPress(TObject *Sender, char &Key);
        void  FormPaint(TObject *Sender);
        void  FormResize(TObject *Sender);
        void  FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  FormActivate(TObject *Sender);
        void  FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void  FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void  FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
        // ----- Serial Communications Code -----
        HANDLE hComm[MAX_COMM];
        COMMTIMEOUTS ctmoNew, ctmoOld[MAX_SERIAL_IN+1];
        char InBuff[MAX_SERIAL_IN+1];

public:		// User declarations
         TsimIO(TComponent* Owner);
         ~TsimIO();
        void  displayFileDialog(long *mode, int A1, int A2, int A3, short *result);
        void  clearKeys();
        void  BringToFront();
        void  setTextSize();
        void  textOut(AnsiString str);
        void  textOutCR(AnsiString str);
        void  setWindowSize(unsigned short width, unsigned short height);
        void  getWindowSize(unsigned short &width, unsigned short &height);
        void  setFontProperties(int c, int s);
        void  gotorc(int x, int y);
        void  getrc(short* d1);
        void  getCharAt(unsigned short r, unsigned short c, char* d1);
        void  textIn(char *, long *, long *);
        void  charIn(char *ch);
        void  charOut(char ch);
        void  doCRLF();
        void  setTextWrap(bool b);
        void  scroll();
        void  scrollRect(ushort r, ushort c, ushort w, ushort h, ushort dir);
        void  erasePrompt();
        void  clear();
        void  playSound(char *fileName, short *result);
        void  loadSound(char *fileName, int waveIndex);
        void  playSoundMem(int waveIndex, short *result);
        void  controlSound(int control, int waveIndex, short *result);
        void  playSoundDX(char *fileName, short *result);
        void  loadSoundDX(char *fileName, int waveIndex, short *result);
        void  playSoundMemDX(int waveIndex, short *result);
        void  stopSoundMemDX(int waveIndex, short *result);
        void  controlSoundDX(int control, int waveIndex, short *result);
        void  drawPixel(int x, int y);
        int   getPixel(int x, int y);
        void  line(int x1, int y1, int x2, int y2);
        void  lineTo(int x, int y);
        void  moveTo(int x, int y);
        void  getXY(short *x, short *y);
        void  setLineColor(int c);
        void  setFillColor(int c);
        void  rectangle(int x1, int y1, int x2, int y2);
        void  ellipse(int x1, int y1, int x2, int y2);
        void  floodFill(int x1, int y1);
        void  unfilledRectangle(int x1, int y1, int x2, int y2);
        void  unfilledEllipse(int x1, int y1, int x2, int y2);
        void  setDrawingMode(int m);
        void  setPenWidth(int w);
        void  getKeyState(long *);
        bool fullScreen;
        void  setupWindow();
        void  drawText(AnsiString str, int x, int y);
        bool InitDirectXAudio(HWND hwnd);
        /*
        bool LoadSegment(HWND hwnd, char *filename, IDirectMusicSegment8* &dmSeg);
        void PlaySegment(IDirectMusicPerformance8* dmPerf, IDirectMusicSegment8* dmSeg);
        void PlaySegmentLoop(IDirectMusicPerformance8* dmPerf, IDirectMusicSegment8* dmSeg);
        void StopSegment(IDirectMusicPerformance8* dmPerf, IDirectMusicSegment8* dmSeg);
        void CloseDown(IDirectMusicPerformance8* dmPerf);
        */
        void ResetSounds();

        void  closeAllComm();
        void  initComm(int cid, char *portName, short *result);
        void  setCommParams(int cid, int settings, short *result);
        void  closeComm(int cid);
        void  readComm(int cid, uchar *n, char *str, short *result);
        void  sendComm(int cid, uchar *n, char *str, short *result);

        void  createNetClient(int settings, char *server, int *result);
        void  createNetServer(int settings, int *result);
        void  sendNet(int settings, char *data, char *remoteIP, int *count, int *result);
        void  receiveNet(int settings, char *buffer, int *count, char *senderIP,  int *result);
        void  sendPortNet(long *D0, long *D1, char *data, char *remoteIP);
        void  receivePortNet(long *D0, long *D1, char *buffer, char *senderIP);
        void  closeNetConnection(int closeIP, int *result);
        void  getLocalIP(char *localIP, int *result);

        TBitmap* BackBuffer;  //this is the backbuffer "surface"
};
//---------------------------------------------------------------------------
extern PACKAGE TsimIO *simIO;
//---------------------------------------------------------------------------

#endif
