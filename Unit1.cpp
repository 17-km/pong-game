//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int numberOfPlayers = 2;

int ballVerticalVelocity = 0;
int ballHorizontalVelocity = 0;

int leftPaddleVelocity = 8;
int rightPaddleVelocity = 8;
int ballVelocity = 14;

int leftPlayerPoints = 0;
int rightPlayerPoints = 0;

int whoStarts = 0;


void centerPaddles()
{
     Form1 -> rightPaddleUp -> Enabled = false;
     Form1 -> rightPaddleDown -> Enabled = false;
     Form1 -> leftPaddleUp -> Enabled = false;
     Form1 -> leftPaddleDown -> Enabled = false;
     Form1 -> leftPaddle -> Top = Form1 -> backgroundForMatch -> Top + Form1 -> backgroundForMatch -> Height/2 - Form1 -> leftPaddle -> Height/2;
     Form1 -> rightPaddle -> Top = Form1 -> backgroundForMatch -> Top + Form1 -> backgroundForMatch -> Height/2 - Form1 -> rightPaddle -> Height/2;
}

void showMenu()
{
     Form1 -> startButton -> Visible = true;
     Form1 -> helpButton -> Visible = true;
     Form1 -> playersModeButton -> Visible = true;
     Form1 -> difficultyLevelButton -> Visible = true;
     Form1 -> exitButton -> Visible = true;
     Form1 -> backgroundForMenu -> Visible = true;
     Form1 -> leftPoints -> Visible = false;
     Form1 -> rightPoints -> Visible = false;

}

void hideMenu()
{
     Form1 -> startButton -> Visible = false;
     Form1 -> helpButton -> Visible = false;
     Form1 -> playersModeButton -> Visible = false;
     Form1 -> difficultyLevelButton -> Visible = false;
     Form1 -> exitButton -> Visible = false;
     Form1 -> backgroundForMenu -> Visible = false;
     centerPaddles();
}

int findStartingPlayer(int whoStartedPreviously)
{
     if (whoStartedPreviously == 0)
     {
          randomize();
          return random(2) + 1;
     }
     else if ((leftPlayerPoints + rightPlayerPoints) % 2 == 0)
     {
          if (whoStartedPreviously == 1) return 2;
          else return 1;
     }
     else
     {
          return whoStartedPreviously;
     }
}

int whoWins()
{
     if (leftPlayerPoints >= 11 && leftPlayerPoints - rightPlayerPoints >= 2)
     {
          return 1;
     }
     else if (rightPlayerPoints >= 11 && rightPlayerPoints - leftPlayerPoints >= 2)
     {
          return 2;
     }
     else
     {
          return 0;
     }
}

void startNewRound()
{
     Form1 -> ballTimer -> Enabled = false;
     Form1 -> ball -> Visible = false;
     Application -> ProcessMessages(); Sleep(1000);
     centerPaddles();
     Form1 -> ball -> Top = Form1 -> backgroundForMatch -> Top + Form1 -> backgroundForMatch -> Height/2 - Form1 -> ball -> Height/2;
     Form1 -> leftPoints -> Caption = IntToStr(leftPlayerPoints);
     Form1 -> rightPoints -> Caption = IntToStr(rightPlayerPoints);

     if (!whoWins())
     {
          Form1 -> ballTimer -> Enabled = false;
          whoStarts = findStartingPlayer(whoStarts);
          ballVerticalVelocity = 0;

          if (whoStarts == 1)
          {
               Form1 -> ball -> Left = Form1 -> leftPaddle -> Left + Form1 -> leftPaddle -> Width;
               ballHorizontalVelocity = ballVelocity;
          }
          else if (whoStarts == 2)
          {
               Form1 -> ball -> Left = Form1 -> rightPaddle -> Left - Form1 -> ball -> Width;
               ballHorizontalVelocity = - ballVelocity;
          }

          Form1 -> ball -> Visible = true;

          Form1 -> counter -> Visible = true;
          Form1 -> counter -> Caption = "3";
          Application -> ProcessMessages(); Sleep(1000);
          Form1 -> counter -> Caption = "2";
          Application -> ProcessMessages(); Sleep(1000);
          Form1 -> counter -> Caption = "1";
          Application -> ProcessMessages(); Sleep(1000);
          Form1 -> counter -> Caption = "START!";
          Application -> ProcessMessages(); Sleep(1000);
          Form1 -> counter -> Visible = false;

          Form1 -> ballTimer -> Enabled = true;
     }
     else
     {
          char* matchResult;

          if (whoWins() == 1) matchResult = "Left player wins! Do you want to play again?";
          else if (whoWins() == 2) matchResult = "Right player wins! Do you want to play again?";

          if (Application -> MessageBox(
          matchResult, "Match Result",
          MB_YESNO | MB_ICONQUESTION) == IDYES)
          {
          Form1 -> startButtonClick(Form1);
          }
          else
          {
          showMenu();
          }
     }
}

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
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if (ballTimer -> Enabled == true)
     {
          if (Key == VK_UP) rightPaddleUp -> Enabled = true;
          if (Key == VK_DOWN) rightPaddleDown -> Enabled = true;
          if (Key == 0x41) leftPaddleUp -> Enabled = true;
          if (Key == 0x5A) leftPaddleDown -> Enabled = true;
          if (Key == VK_ESCAPE)
          {
               ballTimer -> Enabled = false;
               ball -> Visible = false;
               if (Application -> MessageBox(
               "Do you want to end the match and back to main menu?", "Match Paused",
               MB_YESNO | MB_ICONQUESTION) == IDYES)
               {
                    ballTimer -> Enabled = false;
                    ball -> Visible = false;
                    showMenu();
               }
               else
               {
                    ballTimer -> Enabled = true;
                    ball -> Visible = true;
               }
          }
     }
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
void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{
     ball -> Top += ballVerticalVelocity;
     ball -> Left += ballHorizontalVelocity;
     if (ball -> Top <= backgroundForMatch -> Top + 25) ballVerticalVelocity = - ballVerticalVelocity;
     if (ball -> Top + ball -> Height >= backgroundForMatch -> Top + backgroundForMatch -> Height - 25) ballVerticalVelocity = - ballVerticalVelocity;

     else if (ball -> Left <= leftPaddle -> Left + leftPaddle -> Width &&
     ball -> Top + ball -> Height / 2 > leftPaddle -> Top &&
     ball -> Top + ball -> Height / 2 < leftPaddle -> Top + leftPaddle -> Height &&
     ballHorizontalVelocity < 0)
     {
          ballHorizontalVelocity = - ballHorizontalVelocity;
          ballVerticalVelocity = double((ball -> Top + ball -> Height / 2) - (leftPaddle -> Top + leftPaddle -> Height / 2)) / (leftPaddle -> Height / 2) * ballHorizontalVelocity;
     }

     else if (ball -> Left + ball -> Width >= rightPaddle -> Left &&
     ball -> Top + ball -> Height / 2 > rightPaddle -> Top &&
     ball -> Top + ball -> Height / 2 < rightPaddle -> Top + rightPaddle -> Height &&
     ballHorizontalVelocity > 0)
     {
          ballHorizontalVelocity = - ballHorizontalVelocity;
          ballVerticalVelocity = - double((ball -> Top + ball -> Height / 2) - (rightPaddle -> Top + rightPaddle -> Height / 2)) / (rightPaddle -> Height / 2) * ballHorizontalVelocity;
     }

     else if (ball -> Left <= backgroundForMatch -> Left + 5)
     {
          rightPlayerPoints++;
          startNewRound();
     }
     else if (ball -> Left + ball -> Width >= backgroundForMatch -> Left + backgroundForMatch -> Width - 5)
     {
          leftPlayerPoints++;
          startNewRound();
     }

     if (numberOfPlayers == 1)
     {
          if (ball -> Left <= backgroundForMatch -> Left + backgroundForMatch -> Width / 2 &&
          ballHorizontalVelocity < 0)
          {
               if (ball -> Top + ball -> Height / 2 < leftPaddle -> Top + leftPaddle -> Height/4)
               {
                    leftPaddleUp -> Enabled = true;
               }
               else if (ball -> Top + ball -> Height / 2 > leftPaddle -> Top + leftPaddle -> Height*3/4)
               {
                    leftPaddleDown -> Enabled = true;
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
}
//---------------------------------------------------------------------------


void __fastcall TForm1::startButtonClick(TObject *Sender)
{
     hideMenu();
     leftPlayerPoints = 0;
     rightPlayerPoints = 0;
     leftPoints -> Caption = IntToStr(leftPlayerPoints);
     rightPoints -> Caption = IntToStr(rightPlayerPoints);
     leftPoints -> Visible = true;
     rightPoints -> Visible = true;
     whoStarts = 0;
     startNewRound();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::difficultyLevelButtonClick(TObject *Sender)
{
     if (difficultyLevelButton -> Caption == "NORMAL")
     {
          difficultyLevelButton -> Caption = "HARD";
          ballTimer -> Interval = 12;
          leftPaddleDown -> Interval = 12;
          leftPaddleUp -> Interval = 12;
          rightPaddleDown -> Interval = 12;
          rightPaddleUp -> Interval = 12;
     }
     else if (difficultyLevelButton -> Caption == "HARD")
     {
          difficultyLevelButton -> Caption = "EASY";
          ballTimer -> Interval = 20;
          leftPaddleDown -> Interval = 20;
          leftPaddleUp -> Interval = 20;
          rightPaddleDown -> Interval = 20;
          rightPaddleUp -> Interval = 20;
     }
     else if (difficultyLevelButton -> Caption == "EASY")
     {
          difficultyLevelButton -> Caption = "NORMAL";
          ballTimer -> Interval = 17;
          leftPaddleDown -> Interval = 17;
          leftPaddleUp -> Interval = 17;
          rightPaddleDown -> Interval = 17;
          rightPaddleUp -> Interval = 17;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::playersModeButtonClick(TObject *Sender)
{
     if (playersModeButton -> Caption == "TWO-PLAYERS")
     {
          playersModeButton -> Caption = "SINGLE-PLAYER";
          numberOfPlayers = 1;
     }
     else if (playersModeButton -> Caption == "SINGLE-PLAYER")
     {
          playersModeButton -> Caption = "TWO-PLAYERS";
          numberOfPlayers = 2;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
     showMenu();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::exitButtonClick(TObject *Sender)
{
     if (Application -> MessageBox(
     "Do you really want to quit?", "Confirm",
     MB_YESNO | MB_ICONQUESTION) == IDYES)
     {
          Application -> Terminate();
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
     if (Application -> MessageBox(
     "Do you really want to quit?", "Confirm",
     MB_YESNO | MB_ICONQUESTION) == IDNO)
     {
          Action = caNone;
     }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::helpButtonClick(TObject *Sender)
{
     Application -> MessageBox(
     "Welcome to best Pong Game ever!\n\n\n"
     "Key contol: key functions are as follows:\n"
     "- [A] move left paddle up\n"
     "- [Z] move left paddle down\n"
     "- [UP ARROW] move right paddle up\n"
     "- [DOW ARROW] move right paddle down\n"
     "- [ESC]: pause game\n\n"
     "Difficulty levels: one-click on the option in main menu to switch between EASY, NORMAL and HARD difficulty levels\n\n"
     "Players mode: one-click on the option in main menu to switch between SINGLE-PLAYER and TWO-PLAYERS mode\n\n",
     "Pong Game Description",
     MB_OK);
}
//---------------------------------------------------------------------------

