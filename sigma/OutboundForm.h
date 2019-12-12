/*
written by: Alejandro Vasquez
tested by: Alejandro Vasquez
debugged by: Alejandro Vasquez


most of the important code is towards the bottom which uses textboxes and a grid to display data changes.
The buttons are used to enforce these changes.
*/

#pragma once

namespace sigma {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace MySql::Data::MySqlClient;	//allows for mysql connection

	/// <summary>
	/// Summary for OutboundForm
	/// </summary>
	public ref class OutboundForm : public System::Windows::Forms::Form
	{
	public:
		OutboundForm(void)
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
		~OutboundForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::Button^ BackButton;
	private: System::Windows::Forms::Button^ runQueryButton;
	private: System::Windows::Forms::TextBox^ queryTextBox;

	private: System::Windows::Forms::Button^ sendToReportButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ deleteFromOutboundButton;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;

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
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->runQueryButton = (gcnew System::Windows::Forms::Button());
			this->queryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->sendToReportButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->deleteFromOutboundButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(422, 196);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(550, 353);
			this->dataGridView1->TabIndex = 0;
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(842, 12);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(130, 30);
			this->BackButton->TabIndex = 1;
			this->BackButton->Text = L"back";
			this->BackButton->UseVisualStyleBackColor = true;
			// 
			// runQueryButton
			// 
			this->runQueryButton->Location = System::Drawing::Point(842, 48);
			this->runQueryButton->Name = L"runQueryButton";
			this->runQueryButton->Size = System::Drawing::Size(130, 30);
			this->runQueryButton->TabIndex = 2;
			this->runQueryButton->Text = L"Run Query";
			this->runQueryButton->UseVisualStyleBackColor = true;
			this->runQueryButton->Click += gcnew System::EventHandler(this, &OutboundForm::runQueryButton_Click);
			// 
			// queryTextBox
			// 
			this->queryTextBox->Location = System::Drawing::Point(172, 54);
			this->queryTextBox->Multiline = true;
			this->queryTextBox->Name = L"queryTextBox";
			this->queryTextBox->Size = System::Drawing::Size(635, 20);
			this->queryTextBox->TabIndex = 3;
			// 
			// sendToReportButton
			// 
			this->sendToReportButton->Location = System::Drawing::Point(842, 110);
			this->sendToReportButton->Name = L"sendToReportButton";
			this->sendToReportButton->Size = System::Drawing::Size(130, 30);
			this->sendToReportButton->TabIndex = 5;
			this->sendToReportButton->Text = L"Ship";
			this->sendToReportButton->UseVisualStyleBackColor = true;
			this->sendToReportButton->Click += gcnew System::EventHandler(this, &OutboundForm::sendToReportButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(578, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"select orderNumber, itemID, pickedLocation, oQuantity, deliverByDate, customerID "
				L"from legacywms.outbound [condition];";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(112, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Condition:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(112, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 90);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 9;
			// 
			// deleteFromOutboundButton
			// 
			this->deleteFromOutboundButton->Location = System::Drawing::Point(842, 146);
			this->deleteFromOutboundButton->Name = L"deleteFromOutboundButton";
			this->deleteFromOutboundButton->Size = System::Drawing::Size(130, 30);
			this->deleteFromOutboundButton->TabIndex = 10;
			this->deleteFromOutboundButton->Text = L"Delete From Outbound";
			this->deleteFromOutboundButton->UseVisualStyleBackColor = true;
			this->deleteFromOutboundButton->Click += gcnew System::EventHandler(this, &OutboundForm::deleteFromOutboundButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(99, 199);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(215, 20);
			this->textBox1->TabIndex = 11;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(98, 246);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(215, 20);
			this->textBox2->TabIndex = 12;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(98, 296);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(216, 20);
			this->textBox3->TabIndex = 13;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(98, 346);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(215, 20);
			this->textBox4->TabIndex = 14;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(99, 396);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(215, 20);
			this->textBox5->TabIndex = 15;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(97, 446);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(216, 20);
			this->textBox6->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 199);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"orderNumber";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 249);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 13);
			this->label6->TabIndex = 18;
			this->label6->Text = L"itemID";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 299);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(80, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"pickedLocation";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 349);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(52, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"oQuantity";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 399);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(73, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"deliverByDate";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 449);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(61, 13);
			this->label10->TabIndex = 22;
			this->label10->Text = L"customerID";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(320, 249);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(37, 13);
			this->label11->TabIndex = 23;
			this->label11->Text = L"itemID";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(319, 349);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(23, 13);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Qty";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(320, 399);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(67, 13);
			this->label13->TabIndex = 25;
			this->label13->Text = L"dateShipped";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(319, 173);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(65, 13);
			this->label14->TabIndex = 26;
			this->label14->Text = L"Ship Button:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(12, 173);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(75, 13);
			this->label15->TabIndex = 27;
			this->label15->Text = L"Delete Button:";
			// 
			// OutboundForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 561);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->deleteFromOutboundButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->sendToReportButton);
			this->Controls->Add(this->queryTextBox);
			this->Controls->Add(this->runQueryButton);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"OutboundForm";
			this->Text = L"OutboundForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*
		
		all the code bellow gives functionality to the buttons using the textboxes in order to achieve what the desired goals are.
		the buttons name what their actions are intended for.
		
		*/
	private: System::Void runQueryButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ constring = L"datasource=wms-database-3.cnuuwsy8dtiz.us-west-1.rds.amazonaws.com;port=3306;username=root;password=samuraiedge";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand(" select orderNumber, itemID, pickedLocation, oQuantity, deliverByDate, customerID from legacywms.outbound " + this->queryTextBox->Text + ";", conDataBase);
		MySqlDataReader^ myReader;
		try
		{																							//maybe i can put an if statement to help me find when shipping out a locked product... i can have it open an error message as debugging.
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
		 the send to report button will copy the data from outbound and add it into the report table
		 */
	private: System::Void sendToReportButton_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ constring = L"datasource=wms-database-3.cnuuwsy8dtiz.us-west-1.rds.amazonaws.com;port=3306;username=root;password=samuraiedge";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand(" insert into legacywms.report values " "(" + this->textBox2->Text + "," + this->textBox4->Text + "," + this->textBox5->Text + ")" ";", conDataBase);
		MySqlDataReader^ myReader;
		try
		{																							//maybe i can put an if statement to help me find when shipping out a locked product... i can have it open an error message as debugging.
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
		   the delete from outbound button will delete the specified item from the table finalizing the transfer.
		   */
private: System::Void deleteFromOutboundButton_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ constring = L"datasource=wms-database-3.cnuuwsy8dtiz.us-west-1.rds.amazonaws.com;port=3306;username=root;password=samuraiedge";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand(" delete from legacywms.outbound where orderNumber = " +this->textBox2->Text + ";", conDataBase);
	MySqlDataReader^ myReader;
	try
	{																							//maybe i can put an if statement to help me find when shipping out a locked product... i can have it open an error message as debugging.
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
private: System::Void sendToReportTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
