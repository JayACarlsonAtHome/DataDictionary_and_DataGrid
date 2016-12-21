#include <iostream>
#include <iomanip>
#include "DataDictionary.h"


enum         enum_test_result  { unknown = 0, error = 1, good = 2 };


void show_total_results(unsigned int results[]) {
    std::cout << "  Test Result Count of Type Unknown:" << std::setfill('0') << std::setw(4) << results[unknown] << std::endl;
    std::cout << "  Test Result Count of Type Error:  " << std::setfill('0') << std::setw(4) << results[error]   << std::endl;
    std::cout << "  Test Result Count of Type Good:   " << std::setfill('0') << std::setw(4) << results[good]    << std::endl;
    std::cout << std::endl;
}


void show_test_and_results(unsigned int test_number, std::string test_name, unsigned int results[], enum_test_result test_result) {

    results[test_result] += 1;
    std::cout << "Test Number: ";
    std::cout << std::setfill('0') << std::setw(4) << test_number;
    std::cout << "  Test: " << test_name << std::endl;
    show_total_results(results);
}

int main() {

    // initialize variables
    unsigned int results[3]  = {0, 0, 0};
    unsigned int test_number =  0;

    std::cout << std::endl;
    std::cout << "Testing Starting" << std::endl << std::endl;

    test_number++; // 1
    DataColumnHeader* dch = new DataColumnHeader(14, "Header 1", "This is a sample header", "This is a sample header"  );
    std::string str_dch = dch->Get_ColumnHeader();
    unsigned int dch_width = dch->Get_DisplayWidth();
    std::cout << std::endl;
    enum_test_result result = enum_test_result::good;
    std::string test_name = "Make New DataColumnHeader ";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 2
    std::cout << dch->Get_ColumnHeader() << ":  "; dch->Display_Address();
    std::cout << std::endl;
    result = enum_test_result::good;
    test_name = "Show Address ";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 3
    std::string str_cds = dch->Get_ColumnDescriptionShort();
    std::string str_cdl = dch->Get_ColumnDescriptionLong();
    result = enum_test_result::good;
    test_name = "Get descriptions";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 4
    dch->Set_DisplayWidth(20);
    dch->Set_ColumnDescriptionShort("Setting Column Description Short");
    if (dch->Get_ColumnDescriptionShort() == "Setting Column Descr")
    {
        result = enum_test_result::good;
    }
    else
    {
        result = enum_test_result::unknown;
        std::cout << "Short Description: " << dch->Get_ColumnDescriptionShort();
    }
    test_name = "Set and Get Short Description ";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 5
    dch->Set_DisplayWidth(40);
    dch->Set_ColumnDescriptionShort("Setting Column Description Short");
    if (dch->Get_ColumnDescriptionShort() == "Setting Column Description Short")
    {
        result = enum_test_result::good;
    }
    else
    {
        result = enum_test_result::unknown;
        std::cout << "Short Description: " << dch->Get_ColumnDescriptionShort() << std::endl;
    }
    test_name = "Set and Get Short Description Test 2 ";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 6
    dch->Set_DisplayWidth(20);
    dch->Set_ColumnDescriptionLong("Setting Column Description Long");
    if (dch->Get_ColumnDescriptionLong() == "Setting Column Description Long")
    {
        result = enum_test_result::good;
    }
    else
    {
        result = enum_test_result::unknown;
        std::cout << "Long Description: " << dch->Get_ColumnDescriptionLong() << std::endl;
    }
    test_name = "Set and Get Long  Description ";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 7
    DataDictionary dd = DataDictionary();
    if (&dd > 0) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;
    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    test_name = "Create DataDictionary ";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 8
    result = enum_test_result::good;
    dd.Show_DataDictionaryAll();
    test_name = "Show DataDictionary after creation ";
    show_test_and_results(test_number, test_name, results, result);


    test_number++; // 9
    dd.Add_Column(dch);
    if (dd.Get_Size() == 1) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;
    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    test_name = "Show empty data dictionary";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 10
    dd.Add_Column(dch);
    if (dd.Get_Size() == 1) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;

    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    test_name = "Add Duplicate First Column to Data Dictionary ";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 11
    dd.Add_Column(dch);
    if (dd.Get_Size() == 1) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;

    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    test_name = "Add Duplicate First Column to Data Dictionary ";
    show_test_and_results(test_number, test_name, results, result);


    test_number++; // 12
    DataColumnHeader* dch2 = new DataColumnHeader(*dch);
    dch2->Set_ColumnHeader("Header 2");
    dd.Add_Column(dch2);
    if (dd.Get_Size() == 2) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;

    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    test_name = "Add Header 2 to Data Dictionary";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 13
    DataColumnHeader* dch3 = new DataColumnHeader(*dch);
    dch3->Set_ColumnHeader("Header 3");
    dd.Add_Column(dch3);
    if (dd.Get_Size() == 3) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;
    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    test_name = "Add Header 3 to Data Dictionary ";
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 14
    dd.Add_Column(dch3);
    if (dd.Get_Size() == 3) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;

    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    test_name = "Add Header 3 (Duplicate) to Data Dictionary ";
    show_test_and_results(test_number, test_name, results, result);


    test_number++; // 15
    std::string DataGridNumber1 = "Space Ship List";
    dd.Add_DataGrid(DataGridNumber1);
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    unsigned int count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 1) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    test_name = "Add DataGrid " + DataGridNumber1;
    show_test_and_results(test_number, test_name, results, result);


    test_number++; // 16
    dd.Add_DataGrid(DataGridNumber1);
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 1) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    test_name = "Add DataGrid (Duplicate) " + DataGridNumber1;
    show_test_and_results(test_number, test_name,  results, result);


    test_number++; // 17
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 1) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    dd.Show_DataDictionary(DataGridNumber1, 0, 5);
    test_name = "Show Datagrid " + DataGridNumber1 + " before adding columns ";
    show_test_and_results(test_number, test_name,  results, result);


    test_number++; // 18
    std::string DataGridNumber2 = "Space Ship Weapons List";
    dd.Add_DataGrid(DataGridNumber2);
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 2) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    test_name = "Add DataGrid " + DataGridNumber2;
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 19
    std::string DataGridNumber3 = "Enemy Space Ship Weapons List";
    dd.Add_DataGrid(DataGridNumber3);
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 3) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    test_name = "Add DataGrid " + DataGridNumber3;
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 20
    std::string DataGridNumber4 = "Quadrant List";
    dd.Add_DataGrid(DataGridNumber4);
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 4) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    test_name = "Add DataGrid " + DataGridNumber4;
    show_test_and_results(test_number, test_name, results, result);

    test_number++; // 21
    dd.Add_DataGridColumn(DataGridNumber1, "Header 1");
    dd.Add_DataGridColumn(DataGridNumber1, "Header 2");
    dd.Add_DataGridColumn(DataGridNumber1, "Header 3");
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    dd.Show_DataDictionary(DataGridNumber1, 0, 5);
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 4) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    test_name = "Add DataGridColumn Header 1, Header 2, Header 3,  to " + DataGridNumber1;
    show_test_and_results(test_number, test_name, results, result);

    std::cout << "Show_DataDictionaryAll()" << std::endl;
    dd.Show_DataDictionaryAll();

    std::cout << "Results Summary of All Tests" << std::endl;

    delete(dch);
    delete(dch2);
    delete(dch3);

    show_total_results(results);

    return 0;
}



