//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int numberOfPlayers = 1;

int ballVerticalVelocity = 15;
int ballHorizontalVelocity = 15;

int leftPaddleVelocity = 11;
int rightPaddleVelocity = 11;

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
          rightPaddle -> Top += rightPaddleVelocity;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleUpTimer(TObject *Sender)
{
     if(rightPaddle -> Top > backgroundForMatch -> Top + 24)
     {
          rightPaddle -> Top -= rightPaddleVelocity;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if (Key == VK_UP) rightPaddleUp -> Enabled = true;
     if (Key == VK_DOWN) rightPaddleDown -> Enabled = true;
     if (Key == 0x41) leftPaddleUp -> Enabled = true;
     if (Key == 0x5A) leftPaddleDown -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if (Key == VK_UP) rightPaddleUp -> Enabled = false;
     if (Key == VK_DOWN) rightPaddleDown -> Enabled = false;
     if (Key == 0x41) leftPaddleUp -> Enabled = false;
     if (Key == 0x5A) leftPaddleDown -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftPaddleDownTimer(TObject *Sender)
{
     if(leftPaddle -> Top < backgroundForMatch -> Top + backgroundForMatch -> Height - leftPaddle -> Height - 24)
     {
          leftPaddle -> Top += leftPaddleVelocity;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftPaddleUpTimer(TObject *Sender)
{
     if(leftPaddle -> Top > backgroundForMatch -> Top + 24)
     {
          leftPaddle -> Top -= leftPaddleVelocity;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{

     ball -> Top += ballVerticalVelocity;
     ball -> Left += ballHorizontalVelocity;
     if (ball -> Top <= backgroundForMatch -> Top + 25) ballVerticalVelocity = - ballVerticalVelocity;
     if (ball -> Top + ball -> Height >= backgroundForMatch -> Top + backgroundForMatch -> Height - 25) ballVerticalVelocity = - ballVerticalVelocity;

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
          ballHorizontalVelocity = - ballHorizontalVelocity;
          ballVerticalVelocity = double((ball -> Top + ball -> Height / 2) - (leftPaddle -> Top + leftPaddle -> Height / 2)) / (leftPaddle -> Height / 2) * ballHorizontalVelocity;
     }

     else if (ball -> Left + ball -> Width >= rightPaddle -> Left &&
     ball -> Top + ball -> Height / 2 > rightPaddle -> Top &&
     ball -> Top + ball -> Height / 2 < rightPaddle -> Top + rightPaddle -> Height)
     {
          ballHorizontalVelocity = - ballHorizontalVelocity;
          ballVerticalVelocity = - double((ball -> Top + ball -> Height / 2) - (rightPaddle -> Top + rightPaddle -> Height / 2)) / (rightPaddle -> Height / 2) * ballHorizontalVelocity;
     }

     if (numberOfPlayers == 1 &&
     ball -> Left <= backgroundForMatch -> Left + backgroundForMatch -> Width / 2 &&
     ballHorizontalVelocity < 0)
     {
          if (ball -> Top + ball -> Height / 2 < leftPaddle -> Top + leftPaddle -> Height/4)
          {
               leftPaddleUp -> Enabled = true;
               /*if(leftPaddle -> Top > backgroundForMatch -> Top + 24)
               {
                    leftPaddle -> Top -= leftPaddleVelocity;
               }*/
          }
          else if (ball -> Top + ball -> Height / 2 > leftPaddle -> Top + leftPaddle -> Height*3/4)
          {
               leftPaddleDown -> Enabled = true;
               /*if(leftPaddle -> Top < backgroundForMatch -> Top + backgroundForMatch -> Height - leftPaddle -> Height - 24)
               {
                    leftPaddle -> Top += leftPaddleVelocity;
               }*/
          }
          else
          {
          leftPaddleDown -> Enabled = false;
          leftPaddleUp -> Enabled = false;
          }
     }
     else
     {
          leftPaddleDown -> Enabled = false;
          leftPaddleUp -> Enabled = false;
     }

}
//---------------------------------------------------------------------------


