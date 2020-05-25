//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>



//---------------------------------------------------------------------------
class TF_main : public TForm
{
__published:	// IDE-managed Components
	TButton *B_send;
	TEdit *E_msg;
	TMemo *m_chat;
	TButton *Sold;
	TMemo *m_data;
	TMemo *m_answer;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TADOQuery *ADOQuery1;
	TButton *Button1;
	TEdit *Edit1;
	TLabel *Label1;
	TButton *Devide;
	TButton *Output;
	TMemo *memo_mass;
	TStringGrid *StringGrid1;
	TButton *Button2;
	//TButton *Sold;


	void __fastcall B_sendClick(TObject *Sender);
	void __fastcall E_msgKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	//void __fastcall B_analysisClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall OutputClick(TObject *Sender);
	void __fastcall SoldClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	//void __fastcall SoldClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TF_main(TComponent* Owner);

	enum Tmeasure{tdet = 1, ttime = 2};

	struct TinputData{
		 double value;
		 Tmeasure measure;
	 } inputData[10];
	 char **words;
	 char **puncts;
	 int words_number;

};
//---------------------------------------------------------------------------
extern PACKAGE TF_main *F_main;
//---------------------------------------------------------------------------
#endif
