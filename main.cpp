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
    std::string str_dch = dch->GetColumnHeader();
    unsigned int dch_width = dch->GetDisplayWidth();
    std::cout << std::endl;
    enum_test_result result = enum_test_result::good;
    show_test_and_results(test_number, "Make New DataColumnHeader ", results, result);

    test_number++; // 2
    std::cout << dch->GetColumnHeader() << ":  "; dch->Display_Address();
    std::cout << std::endl;
    result = enum_test_result::good;
    show_test_and_results(test_number, "Show Address ", results, result);

    test_number++; // 3
    std::string str_cds = dch->GetColumnDescriptionShort();
    std::string str_cdl = dch->GetColumnDescriptionLong();
    result = enum_test_result::good;
    show_test_and_results(test_number, "Get descriptions", results, result);

    dch->Set_ColumnDescriptionLong( "Setting Column Description Long");

    test_number++; // 4
    dch->Set_DisplayWidth(20);
    dch->Set_ColumnDescriptionShort("Setting Column Description Short");
    if (dch->GetColumnDescriptionShort() == "Setting Column Descr")
    {
        result = enum_test_result::good;
    }
    else
    {
        result = enum_test_result::unknown;
        std::cout << "Short Description: " << dch->GetColumnDescriptionShort();
    }
    show_test_and_results(test_number, "Set and Get Short Description", results, result);

    test_number++;
    dch->Set_DisplayWidth(40);
    dch->Set_ColumnDescriptionShort("Setting Column Description Short");
    if (dch->GetColumnDescriptionShort() == "Setting Column Description Short")
    {
        result = enum_test_result::good;
    }
    else
    {
        result = enum_test_result::unknown;
        std::cout << "Short Description: " << dch->GetColumnDescriptionShort() << std::endl;
    }
    show_test_and_results(test_number, "Set and Get Short Description Test 2", results, result);


    test_number++;
    dch->Set_DisplayWidth(20);
    dch->Set_ColumnDescriptionLong("Setting Column Description Long");
    if (dch->GetColumnDescriptionLong() == "Setting Column Description Long")
    {
        result = enum_test_result::good;
    }
    else
    {
        result = enum_test_result::unknown;
        std::cout << "Long Description: " << dch->GetColumnDescriptionLong() << std::endl;
    }
    show_test_and_results(test_number, "Set and Get Long  Description", results, result);

    test_number++;
    DataDictionary dd = DataDictionary();
    if (&dd > 0) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;
    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    show_test_and_results(test_number, "Create DataDictionary", results, result);

    test_number++;
    dd.Add_Column(dch);
    if (dd.Get_Size() == 1) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;
    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    show_test_and_results(test_number, "Add First Column to Data Dictionary", results, result);

    test_number++;
    dd.Add_Column(dch);
    if (dd.Get_Size() == 1) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;

    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    show_test_and_results(test_number, "Add Duplicate First Column to Data Dictionary", results, result);

    test_number++;
    dd.Add_Column(dch);
    if (dd.Get_Size() == 1) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;

    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    show_test_and_results(test_number, "Add Duplicate First Column to Data Dictionary", results, result);


    test_number++;
    DataColumnHeader* dch2 = new DataColumnHeader(*dch);
    dch2->Set_ColumnHeader("Header 2");
    dd.Add_Column(dch2);
    if (dd.Get_Size() == 2) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;

    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    show_test_and_results(test_number, "Add Header 2 to Data Dictionary", results, result);


    test_number++;
    DataColumnHeader* dch3 = new DataColumnHeader(*dch);
    dch3->Set_ColumnHeader("Header 3");
    dd.Add_Column(dch3);
    if (dd.Get_Size() == 3) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;

    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    show_test_and_results(test_number, "Add Header 3 to Data Dictionary", results, result);

    test_number++;
    dd.Add_Column(dch3);
    if (dd.Get_Size() == 3) {
        result = enum_test_result::good;
    } else {
        result = enum_test_result::unknown;

    }
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    show_test_and_results(test_number, "Add Header 3 (Duplicate) to Data Dictionary", results, result);

    test_number++;
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    dd.Show_DataDictionary("", 0, dd.Get_Size());
    result = enum_test_result::good;
    show_test_and_results(test_number, "Show Data Dictionary", results, result);


    test_number++;
    dd.Add_DataGrid("Space Ships List");
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    unsigned int count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 1) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    show_test_and_results(test_number, "Add DataGrid Space Ship List", results, result);


    test_number++;
    dd.Add_DataGrid("Space Ships List");
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 1) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    show_test_and_results(test_number, "Add DataGrid (Duplicate) Space Ship List", results, result);

    test_number++;
    dd.Add_DataGrid("Space Ship Weapons List");
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 2) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    show_test_and_results(test_number, "Add DataGrid Space Ship Weapons List", results, result);

    test_number++;
    dd.Add_DataGrid("Enemy Space Ship Weapons List");
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 3) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    show_test_and_results(test_number, "Add DataGrid Enemy Ship Weapons List", results, result);

    test_number++;
    dd.Add_DataGrid("Quadrant List");
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 4) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    show_test_and_results(test_number, "Add DataGrid Quadrant List", results, result);

    test_number++;
    dd.Add_DataGridColumn("Space Ship List", "Header 1");
    std::cout << "dd.Get_Size(): " << dd.Get_Size() << std::endl;
    count = dd.Get_CountofDataGrids();
    dd.Show_DataDictionary("Space Ship List", 0, 5);
    std::cout << "dd.Get_CountofDataGrids: " << count << std::endl;
    if (count == 4) {
        result = enum_test_result::good;
    } else
    {
        result = enum_test_result::unknown;
    }
    show_test_and_results(test_number, "Add DataGrid Quadrant List", results, result);


    show_total_results(results);





    return 0;
}



