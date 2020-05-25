//---------------------------------------------------------------------------

#include <vcl.h>
#include<cmath>
#include <alloc.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_main *F_main;
//---------------------------------------------------------------------------
__fastcall TF_main::TF_main(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_main::B_sendClick(TObject *Sender)
{
  // [<type_tag>] {<constant_name> [= <value>], ...} [var_list];

 struct TinputData t;

 t.value = 1.5;
 t.measure = tdet;

	TDateTime* myTime = new TDateTime(Now());
	String text= myTime->FormatString("dd.mm.yyyy") +
		" " + myTime->FormatString("hh:mm") + " Я: " + " " + E_msg->Text;
	m_chat->Lines->Add(text);


	if(E_msg->Text.Pos("Привет")){
		String text= "Бот: " + myTime->FormatString("dd.mm.yyyy") +
		" " + myTime->FormatString("hh:mm") + " " + "Привет";
		m_chat->Lines->Add(text);
		}
	if  (E_msg->Text.Pos("Пока")) {
		String text= "Бот: " + myTime->FormatString("dd.mm.yyyy") +
		" " + myTime->FormatString("hh:mm") + " " + "Пока человек";
		m_chat->Lines->Add(text);
		 }
	   if  (E_msg->Text.Pos("дела") && E_msg->Text.Pos("?")){
			if (E_msg->Text.Length() == E_msg->Text.Pos("?")){
			String text= "Бот: " + myTime->FormatString("dd.mm.yyyy") +
			" " + myTime->FormatString("hh:mm") + " " + "Пытаюсь освоить С++";
				m_chat->Lines->Add(text);
	   }
	   else {
		   String text= "Бот: " + myTime->FormatString("dd.mm.yyyy") +
			" " + myTime->FormatString("hh:mm") + " " + "Задай вопрос правильно!";
				m_chat->Lines->Add(text);
		 }
	   }
}
//---------------------------------------------------------------------------
void __fastcall TF_main::E_msgKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == '\r'){
	  B_sendClick(Sender);
	}

}
//---------------------------------------------------------------------------



void __fastcall TF_main::SoldClick(TObject *Sender)
{
   int p;
   int dL = 0;
   int i;
   int wordBuf;
   bool cancel = false; // отменяет замену "час" после цифр
   bool numFound = false;
   bool connect = false; // возможно можно соединить цифру
   bool down = false; // вырезать первую часть цифры и поставить конечное значение
   char *measureText[] = {"неизвестная величина","деталей","час"};
   String text =  m_chat->Lines->GetText();
  // text ;
	String word;
	do{
		p = text.Pos(" ");
		if(p == 0){
			word = text;
		}
		else{
			word = text.SubString(1, p-1); // вырезаем текст и копируем заново
			text = text.SubString(p+1, text.Length());
		}

		cancel = false;  // обнуление cancel

		if(numFound == true){
			if(word == "деталь" || word == "деталей"){
				inputData[dL-1].measure = tdet;

			}
			if(word == "час" || word == "часа" || word == "часов"){
				inputData[dL-1].measure = ttime;
				cancel = true;

			}
		  numFound = false;
		}

		// СОЕДИНЕНИЕ цифр
		   if (connect == true) {
			  if(word == "Пять" || word == "пять"){
			   wordBuf = 5;
			   word = inputData[dL-1].value + wordBuf;
			  // m_chat->Lines->Add("Суммирование дало " + word);
			   down = true;
			 }
			  else if(word == "Семьдесят" || word == "семьдесят"){
			   wordBuf = 70;
			   word = inputData[dL-1].value + wordBuf;
			  // m_chat->Lines->Add("Суммирование дало " + word);
			   down = true;
			 }
			 else if(word == "Пятьдесят" || word == "пятьдесят"){
			   wordBuf = 50;
			   word = inputData[dL-1].value + wordBuf;
			   //m_chat->Lines->Add("Суммирование дало " + word);
			   down = true;
			 }
			 else if(word == "Один" || word == "один"){
			   wordBuf = 1;
			   word = inputData[dL-1].value + wordBuf;
			   //m_chat->Lines->Add("Суммирование дало " + word);
			   down = true;
			 }

			 connect = false; //обнуление connect

		   }
		//

		//СЛОВАРЬ с помощью if
		if (word == "Один" || word == "один") {
		//m_chat->Lines->Add("Замена " + word + " на число 1");
			word = 1;
		   //	m_chat->Lines->Add(word);
			connect = true;
		}
		else if (word == "Два" || word == "два") {
	   //m_chat->Lines->Add("Замена " + word + " на число 2");
			word = 2;
			//m_chat->Lines->Add(word);
			connect = true;
		}
		else if (word == "Пятьдесят" || word == "пятьдесят") {
		//m_chat->Lines->Add("Замена " + word + " на число 50");
			word = 50;
		   //	m_chat->Lines->Add(word);
			connect = true;
		}
		else if (word == "Сто" || word == "сто") {
		//m_chat->Lines->Add("Замена " + word + " на число 100");
			word = 100;
		   //	m_chat->Lines->Add(word);
			connect = true;
		}
		else if (word == "Семьдесят" || word == "семьдесят") {
		//m_chat->Lines->Add("Замена " + word + " на число 70");
			word = 70;
			//m_chat->Lines->Add(word);
			connect = true;
		}
		else if (word == "Пять" || word == "пять") {
		//m_chat->Lines->Add("Замена " + word + " на число 5");
			word = 5;
			//m_chat->Lines->Add(word);
			connect = true;
		}
		else if (word == "час" && cancel == false){
		m_data->Lines->Add("Замена " + word + " на число 1");
		 word = 1;
		 inputData[dL].measure = ttime;
		// m_chat->Lines->Add(word);
		}
		else if (word == "три" || word == "Три" && cancel == false){
		//m_chat->Lines->Add("Замена " + word + " на число 1");
		 word = 3;
		 inputData[dL].measure = ttime;
		// m_chat->Lines->Add(word);
		}
		else{
		m_data->Lines->Add(word);
		}
		//

		if(down == false){ //РАЗОБРАТЬСЯ КАК РАБОТАЕТ ПОЭТАПНО (пример со 150 в середине
		                                                                        //текста)
		try{
			inputData[dL].value = word.ToDouble();
			numFound = true;
			connect = true;
			dL++;
			//m_chat->Lines->Add("Число");
		   }
		catch(const Exception& e)
			{
		//словарь
			}
		}

		else{
		try{
			inputData[dL-1].value = word.ToDouble();
			numFound = true;
			connect = true;
			down = false;
			//dL++;
			//m_chat->Lines->Add("Число");
		   }
		   catch(const Exception& e)
			 {
		//словарь
			 }
		}
  //
   }while(p);

	for(i = 0;i < dL; i++){
		m_data->Lines->Add(FloatToStr(inputData[i].value) +" "+
			measureText[inputData[i].measure]);
	}


   // 3 СЕМ
	  //m_chat->Lines->Add("Пытаюсь решить");
   int z;
   String textf = m_chat->Lines->GetText();
   z = textf.Pos("Сколько деталей");

	if (z == 0) {
		m_chat->Lines->Add("Нет решения");
		return;
	}
	int X = 0;  // кол-во деталей 2
	int X1;   // решения кв ур
	int X2;
	int D; //дескр
	int N[10];
	int T[10];
	int j;
	int jt = 0;
	int jd = 0;

	for (j = 0; j < dL; j++) {   // заполнение массивов значений
			if (inputData[j].measure == tdet) {
				N[jd] = inputData[j].value;
				jd++;
			}
			if (inputData[j].measure == ttime) {
				T[jt] = inputData[j].value;
				jt++;
			}
	}

	//решение

	D = pow((T[0]*N[1]),2) + 4*(T[0]*N[0]*N[1]);
	m_answer->Lines->Add("D= " + IntToStr(D));

	X1 = (-T[0]*N[1]+sqrt(D))/(2*T[0]);
	m_answer->Lines->Add("X1= " + IntToStr(X1));

	X2 = (-T[0]*N[1]-sqrt(D))/(2*T[0]);
	m_answer->Lines->Add("X2= " + IntToStr(X2));

	if (X1 < 0) {
	X = X2;
	m_answer->Lines->Add("Ответ:" + IntToStr(X));
	}
	else if (X2 < 0) {
	X = X1;
	m_answer->Lines->Add("Ответ:" + IntToStr(X));	
	}
	else{
	m_answer->Lines->Add("Все ответы < 0");
	}
	}

	// доп задачи  про движение по воде
	// блок решений: if else {решение} if else {.....}



	// лаба 5 динамическое выделение памяти





//---------------------------------------------------------------------------

void __fastcall TF_main::Button1Click(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM `numbers` where word=:param1");
	ADOQuery1->Parameters->ParamByName("param1")->Value = Edit1->Text;
	ADOQuery1->Open();
	AnsiString str = ADOQuery1->FieldByName("number")->AsString;
	Label1->Caption = str;

}
//---------------------------------------------------------------------------




void __fastcall TF_main::OutputClick(TObject *Sender)
{
   int p;
   int i;
   int l;
   int d;  // dot
   int c; // comma
   int q; //questin
   int wordBuf;
   //bool numFound = false;
   char *measureText[] = {"неизвестная величина","деталей","час"};
	String text = m_chat->Lines->GetText();
	String word;
	String punct = NULL;
	words = (char**) 0;
	words = NULL;  // массив слов
	puncts = NULL;
	words_number = 0;
	char *pc = NULL; // array for words
	do{
			p = text.Pos(" ");
			if(p == 0){
				word = text;
				d = word.Pos(".");
				q = word.Pos("?");
				if (d != 0) {
					punct = word.SubString(d,d);
					word = text.SubString(1, d-1);
				}
				 else if (q != 0) {
					punct = word.SubString(q,q);
					word = text.SubString(1, q-1);
				}
			}
			else{
				word = text.SubString(1, p-1); // вырезаем текст и копируем заново
				text = text.SubString(p+1, text.Length());
				l = word.Length();
				c = word.Pos(",");
				d = word.Pos(".");
				//String punct;
				if (l == c || l == d) {
				punct = word.SubString(word.Length(), word.Length());
				word = word.SubString(1, word.Length()-1); // обрезаем точку или запятую?
					}
				}
				pc = (char *)malloc(word.Length() + 1); // содержится адрес памяти для слова
					if (pc == NULL) {
						return;
					}
					words_number++;
					if(words == NULL){
						words = (char **)malloc(words_number * sizeof(char *));
					}
					else{
						words = (char **)realloc(words, words_number * sizeof(char *));
					}
				   //strcpy(pc, word.c_str());
					WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, word.c_str(), -1, pc,word.Length()+1 , NULL, NULL);
					words[words_number-1] = pc;
					if (punct != NULL) {
						pc = (char *)malloc(punct.Length() + 1); // содержится адрес памяти для слова
						if (pc == NULL) {
							return;
					}
					words_number++;
					if(words == NULL){
						words = (char **)malloc(words_number * sizeof(char *));
					}
					else{
						words = (char **)realloc(words, words_number * sizeof(char *));
					}
				   //strcpy(pc, word.c_str());
					WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, punct.c_str(), -1, pc,punct.Length()+1 , NULL, NULL);
					words[words_number-1] = pc;
					punct = NULL;
					}

		}while(p);

		for(i = 0;i < words_number; i++){
			memo_mass->Lines->Add(words[i]);
	}
		//for(i = 0;i < words_number; i++){
		   //	memo_mass->Lines->Add(puncts[i]);
	//}
   }
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TF_main::Button2Click(TObject *Sender)
{
	//randomize();
	//int p;
	//int dL = 0;
	//char *measureText[] = {"неизвестная величина","деталей","час"};

   //	for (i = 0; i < word_number; i++) {

	}
//---------------------------------------------------------------------------


