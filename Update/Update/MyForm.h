//Written by: Andres Dominguez
//Tested by: Andres Dominguez
//Debugged by: Andres Dominguez
#pragma once

namespace Update {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Update_btn;

	private: System::Windows::Forms::TextBox^ txt_id;
	private: System::Windows::Forms::Label^ label_id;
	private: System::Windows::Forms::TextBox^ txt_name;
	private: System::Windows::Forms::TextBox^ txt_surname;
	private: System::Windows::Forms::TextBox^ txt_age;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ viewtable;











	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Update_btn = (gcnew System::Windows::Forms::Button());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->label_id = (gcnew System::Windows::Forms::Label());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->txt_surname = (gcnew System::Windows::Forms::TextBox());
			this->txt_age = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->viewtable = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// Update_btn
			// This button will update the database when clicked.
			// 
			this->Update_btn->Location = System::Drawing::Point(350, 371);
			this->Update_btn->Name = L"Update_btn";
			this->Update_btn->Size = System::Drawing::Size(75, 23);
			this->Update_btn->TabIndex = 0;
			this->Update_btn->Text = L"Update";
			this->Update_btn->UseVisualStyleBackColor = true;
			this->Update_btn->Click += gcnew System::EventHandler(this, &MyForm::Update_btn_Click);
			// 
			// txt_id
			// This is where the user will type in the ID.
			// 
			this->txt_id->Location = System::Drawing::Point(12, 113);
			this->txt_id->Name = L"txt_id";
			this->txt_id->Size = System::Drawing::Size(100, 20);
			this->txt_id->TabIndex = 2;
			this->txt_id->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
			// 
			// label_id
			// This is the label for the textbox where ID is inputed.
			// 
			this->label_id->AutoSize = true;
			this->label_id->Location = System::Drawing::Point(30, 136);
			this->label_id->Name = L"label_id";
			this->label_id->Size = System::Drawing::Size(61, 13);
			this->label_id->TabIndex = 3;
			this->label_id->Text = L"customerID";
			this->label_id->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// txt_name
			// This is where the user inputs the name.
			// 
			this->txt_name->Location = System::Drawing::Point(12, 168);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(100, 20);
			this->txt_name->TabIndex = 4;
			// 
			// txt_surname
			// This is where the Address is inputed.
			// 
			this->txt_surname->Location = System::Drawing::Point(12, 218);
			this->txt_surname->Name = L"txt_surname";
			this->txt_surname->Size = System::Drawing::Size(100, 20);
			this->txt_surname->TabIndex = 5;
			// 
			// txt_age
			// This is where the user will enter the City of the customer.
			// 
			this->txt_age->Location = System::Drawing::Point(12, 269);
			this->txt_age->Name = L"txt_age";
			this->txt_age->Size = System::Drawing::Size(100, 20);
			this->txt_age->TabIndex = 6;
			// 
			// label1
			//This is the label for the name textbox.
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 191);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Name";
			// 
			// label2
			// This label is for the address textbox
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 241);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Address";
			// 
			// label3
			// This label is for the city.
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(52, 292);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"City";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// dataGridView1
			// This displays the customer table.
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(218, 113);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(309, 213);
			this->dataGridView1->TabIndex = 10;
			// 
			// viewtable
			// 
			this->viewtable->Location = System::Drawing::Point(256, 371);
			this->viewtable->Name = L"viewtable";
			this->viewtable->Size = System::Drawing::Size(75, 23);
			this->viewtable->TabIndex = 11;
			this->viewtable->Text = L"View Table";
			this->viewtable->UseVisualStyleBackColor = true;
			this->viewtable->Click += gcnew System::EventHandler(this, &MyForm::viewtable_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(539, 437);
			this->Controls->Add(this->viewtable);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_age);
			this->Controls->Add(this->txt_surname);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->label_id);
			this->Controls->Add(this->txt_id);
			this->Controls->Add(this->Update_btn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Update_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ constring = L"datasource=wms-database-3.cnuuwsy8dtiz.us-west-1.rds.amazonaws.com;port=3306;username=root;password=samuraiedge";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("Update legacywms.customer set customerID='" + this->txt_id->Text + "',cName='" + this->txt_name->Text + "',cAdress='" + this->txt_surname->Text + "',cCity='" + this->txt_age->Text + "'Where customerID='" + this->txt_id->Text + "';", conDataBase);
		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();
			MessageBox::Show("Updated");
			while (myReader->Read()) {

			}
			
		}
		catch (Exception ^ ex) {
			MessageBox::Show(ex->Message);
		}


	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	
	

			

		private: System::Void Msg_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void viewtable_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ constring = L"datasource=wms-database-3.cnuuwsy8dtiz.us-west-1.rds.amazonaws.com;port=3306;username=root;password=samuraiedge";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand(" Select customerID, cName, cAdress, cCity from legacywms.customer;", conDataBase); //StockQuantity != '10' i added this because our aws database needs to have the datatypes changed for stockQuantity...
	MySqlDataReader^ myReader;
	try
	{
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();	sda->SelectCommand = cmdDataBase;
		DataTable^ dbdataset = gcnew DataTable();
		sda->Fill(dbdataset);
		BindingSource^ bSource = gcnew BindingSource();

		bSource->DataSource = dbdataset;
		dataGridView1->DataSource = bSource;
		sda->Update(dbdataset);
	}
	catch (Exception ^ ex)
	{
		MessageBox::Show(ex->Message);
	}
}
};
		 };
	