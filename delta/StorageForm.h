/*
written by: Alejandro Vasquez
tested by: Alejandro Vasquez
debugged by: Alejandro Vasquez

this program allows you to do query searches and see data in the storage form
*/

#pragma once

namespace delta {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;	//allows for mysql connection

	/// <summary>
	/// Summary for StorageForm
	/// </summary>
	public ref class StorageForm : public System::Windows::Forms::Form
	{
	public:
		StorageForm(void)
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
		~StorageForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ runQueryButton;
	private: System::Windows::Forms::Button^ backButton;
	private: System::Windows::Forms::Button^ lowActiveProductButton;
	private: System::Windows::Forms::TextBox^ queryTextBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->runQueryButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->lowActiveProductButton = (gcnew System::Windows::Forms::Button());
			this->queryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(128, 136);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(644, 413);
			this->dataGridView1->TabIndex = 20;
			// 
			// runQueryButton
			// 
			this->runQueryButton->Location = System::Drawing::Point(526, 12);
			this->runQueryButton->Name = L"runQueryButton";
			this->runQueryButton->Size = System::Drawing::Size(120, 30);
			this->runQueryButton->TabIndex = 21;
			this->runQueryButton->Text = L"Run Query";
			this->runQueryButton->UseVisualStyleBackColor = true;
			this->runQueryButton->Click += gcnew System::EventHandler(this, &StorageForm::runQueryButton_Click);
			// 
			// backButton
			// 
			this->backButton->Location = System::Drawing::Point(652, 12);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(120, 30);
			this->backButton->TabIndex = 22;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = true;
			// 
			// lowActiveProductButton
			// 
			this->lowActiveProductButton->Location = System::Drawing::Point(652, 48);
			this->lowActiveProductButton->Name = L"lowActiveProductButton";
			this->lowActiveProductButton->Size = System::Drawing::Size(120, 30);
			this->lowActiveProductButton->TabIndex = 23;
			this->lowActiveProductButton->Text = L"Low Active Product";
			this->lowActiveProductButton->UseVisualStyleBackColor = true;
			this->lowActiveProductButton->Click += gcnew System::EventHandler(this, &StorageForm::lowActiveProductButton_Click);
			// 
			// queryTextBox
			// 
			this->queryTextBox->Location = System::Drawing::Point(128, 110);
			this->queryTextBox->Multiline = true;
			this->queryTextBox->Name = L"queryTextBox";
			this->queryTextBox->Size = System::Drawing::Size(644, 20);
			this->queryTextBox->TabIndex = 24;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(125, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Query Condition:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(564, 13);
			this->label2->TabIndex = 26;
			this->label2->Text = L"Select storageLocationID, storageLocationName, itemName, StockQuantity from legac"
				L"ywms.storage [Query Condtion];";
			// 
			// StorageForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->queryTextBox);
			this->Controls->Add(this->lowActiveProductButton);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->runQueryButton);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"StorageForm";
			this->Text = L"StorageForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*
		the run query button will run a query shown to the user.
		they will be able to edit the parameters of their query search to their content.
		*/
private: System::Void runQueryButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ constring = L"datasource=wms-database-3.cnuuwsy8dtiz.us-west-1.rds.amazonaws.com;port=3306;username=root;password=samuraiedge";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand(" Select storageLocationID, storageLocationName, itemName, StockQuantity from legacywms.storage " + this->queryTextBox->Text + ";", conDataBase);
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
	   /*
		the low active product button will show all product in the active storage that have less than 5 items.
		this will be to help the workers know what needs to be restocked.
	   */

private: System::Void lowActiveProductButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ constring = L"datasource=wms-database-3.cnuuwsy8dtiz.us-west-1.rds.amazonaws.com;port=3306;username=root;password=samuraiedge";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand(" Select storageLocationID, storageLocationName, itemName, StockQuantity from legacywms.storage where storageLocationName = 'Active' AND StockQuantity <= '5' and StockQuantity != '10';", conDataBase); //StockQuantity != '10' i added this because our aws database needs to have the datatypes changed for stockQuantity...
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
}
