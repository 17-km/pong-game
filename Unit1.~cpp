//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int verticalVelocity = -10;
int horizontalVelocity = 10;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleDownTimer(TObject *Sender)
{
     if(rightPaddle -> Top < backgroundForMatch -> Top + backgroundForMatch -> Height - rightPaddle -> Height - 24)
     {
          rightPaddle -> Top += 11;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleTopTimer(TObject *Sender)
{
     if(rightPaddle -> Top > backgroundForMatch -> Top + 24)
     {
          rightPaddle -> Top -= 11;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if (Key == VK_UP) rightPaddleTop -> Enabled = true;
     if (Key == VK_DOWN) rightPaddleDown -> Enabled = true;
     if (Key == 0x41) leftPaddleTop -> Enabled = true;
     if (Key == 0x5A) leftPaddleDown -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if (Key == VK_UP) rightPaddleTop -> Enabled = false;
     if (Key == VK_DOWN) rightPaddleDown -> Enabled = false;
     if (Key == 0x41) leftPaddleTop -> Enabled = false;
     if (Key == 0x5A) leftPaddleDown -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftPaddleDownTimer(TObject *Sender)
{
     if(leftPaddle -> Top < backgroundForMatch -> Top + backgroundForMatch -> Height - leftPaddle -> Height - 24)
     {
          leftPaddle -> Top += 11;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftPaddleTopTimer(TObject *Sender)
{
     if(leftPaddle -> Top > backgroundForMatch -> Top + 24)
     {
          leftPaddle -> Top -= 11;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{

     ball -> Top += verticalVelocity;
     ball -> Left += horizontalVelocity;
     if (ball -> Top <= backgroundForMatch -> Top + 25) verticalVelocity = - verticalVelocity;
     if (ball -> Top + ball -> Height >= backgroundForMatch -> Top + backgroundForMatch -> Height - 25) verticalVelocity = - verticalVelocity;

     if (ball -> Left <= backgroundForMatch -> Left + 5)
     {
          ballTimer -> Enabled = false;
          ball -> Visible = false;
     }

     if (ball -> Left + ball -> Width >= backgroundForMatch -> Left + backgroundForMatch -> Width - 5)
     {
          ballTimer -> Enabled = false;
          ball -> Visible = false;
     }

     else if (ball -> Left <= leftPaddle -> Left + leftPaddle -> Width &&
     ball -> Top + ball -> Height / 2 > leftPaddle -> Top &&
     ball -> Top + ball -> Height / 2 < leftPaddle -> Top + leftPaddle -> Height)
     {
          horizontalVelocity = - horizontalVelocity;
          verticalVelocity = double((ball -> Top + ball -> Height / 2) - (leftPaddle -> Top + leftPaddle -> Height / 2)) / (leftPaddle -> Height / 2) * horizontalVelocity;
     }

     else if (ball -> Left + ball -> Width >= rightPaddle -> Left &&
     ball -> Top + ball -> Height / 2 > rightPaddle -> Top &&
     ball -> Top + ball -> Height / 2 < rightPaddle -> Top + rightPaddle -> Height)
     {
          horizontalVelocity = - horizontalVelocity;
          verticalVelocity = - double((ball -> Top + ball -> Height / 2) - (rightPaddle -> Top + rightPaddle -> Height / 2)) / (rightPaddle -> Height / 2) * horizontalVelocity;
     }

}
//---------------------------------------------------------------------------

