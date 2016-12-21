//
// Created by jay on 12/14/16.
//

#include "DataColumnHeader.h"
#include "DataDictionary.h"


//
// Private Methods
//

bool DataDictionary::Ensure_MaxDataColumnHeaderDataGridIndexValid(std::string data_grid_name, unsigned long found_data_grid_index)
{
    bool result = false;
    try {

        found_data_grid_index = Get_Data_Grid_Index(data_grid_name);
        if (found_data_grid_index != -1) {
            this->m_data_grid_column.at(found_data_grid_index);
            result = true;
        }
    }
    catch (const std::out_of_range& oor) {
        try {
            std::cout << "Attempting to add a row to vector m_data_grid_column..." << std::endl;
            std::vector<unsigned long> row;
            row.push_back(found_data_grid_index);
            this->m_data_grid_column.push_back(row);
            result = true;
            std::cout << "Attempt completed successfully..." << std::endl;
        }
        catch (const __exception e)
        {
            Show_Exception(e);
        }
    }
    return result;
}

unsigned long DataDictionary::Get_Data_Grid_Index(std::string data_grid_name)
{
    //
    // early return possible in this method
    //
    unsigned long result = -1;
    unsigned long max = this->m_data_grid_name.size();
    bool cont = true;
    for (unsigned long i = 0; i < max; i++) {
        if (this->m_data_grid_name[i] == data_grid_name) {
            result = i;
            // early return here
            return result;
        }
    }
    return result;
}

unsigned long DataDictionary::Get_DataColumnHeaderIndex(std::string data_column_header)
{
    unsigned long result = -1;
    if (!m_is_full)
    {
        for (unsigned long i = 0; i < m_data_dictionary_size; i++) {
            if (m_data_column_header[i].Get_ColumnHeader() == data_column_header) {
                result = i;
            }
        }
    }
    return result;
}

void DataDictionary::Add_ColumnNow(DataColumnHeader* dch)
{
    this->m_data_column_header.push_back(*dch);
    this->m_data_dictionary_size += 1;
}

void DataDictionary::Clear()
{
    m_is_full = false;
    m_data_column_header.clear();
    m_data_grid_name.clear();
    m_data_grid_size.clear();
    m_data_grid_column.clear();
}

void DataDictionary::Display_Column(unsigned long i)
{
    // This prints out all the data columns of the data dictionary or at least between start and stop
    std::cout << "DataDictionary Column Number:  " << std::setfill('0') << std::setw(4) << i << std::endl;
    Display_Address(i);
    std::cout << "  Column Name:    "           << m_data_column_header[i].Get_ColumnHeader() << std::endl;
    std::cout << "  Column Width:   "           << m_data_column_header[i].Get_DisplayWidth() << std::endl;
    std::cout << "  Column Short Description: " << m_data_column_header[i].Get_ColumnDescriptionShort() << std::endl;
    std::cout << "  Column Long  Description: " << m_data_column_header[i].Get_ColumnDescriptionLong()  << std::endl;
    std::cout << std::endl << std::endl;
}

void DataDictionary::Display_DataGridNotFound(std::string data_grid_name)
{
    std::cout << "Warning!!! Datagrid named: " << data_grid_name << " not found!" << std::endl;
}

void DataDictionary::Init()
{
    Clear();
    this->m_data_dictionary_size = 0;
}

void DataDictionary::Show_DataDictionaryEmpty()
{
    std::cout << "The data dictionary is empty." << std::endl;
}

void DataDictionary::Show_DataGridEmpty()
{
    std::cout << "The are no Datagrid columns defined." << std::endl;
}

//
// Public Methods
//


DataDictionary::DataDictionary()
{
    Init();
}

DataDictionary::~DataDictionary()
{
    Clear();
}

void DataDictionary::Show_DataDictionaryAll()
{
    if (!m_data_column_header.empty()) {
        unsigned long max = m_data_column_header.size();
        for (unsigned long i = 0; i < max; i++) {
            Display_Column(i);
        }
    }
    else
    {
        Show_DataDictionaryEmpty();
    }
}

void DataDictionary::Show_DataDictionary(std::string data_grid_name, unsigned long start, unsigned long stop)
{
    unsigned long index = 0;
    unsigned long size = Get_Size(data_grid_name);
    if ((size > 0) && (size != -1))
    {
        for (unsigned long i = 0; i < size; i++)
        {
            index = static_cast<unsigned long>(i);
            Display_Column(index);
        }
    }
    else
    {
        Show_DataGridEmpty();
    }
}

void DataDictionary::Add_DataGrid(std::string datagrid_name)
{
    //ensure that this is a new (unique) data grid.
    unsigned long found = Get_Data_Grid_Index(datagrid_name);
    if (found == -1) {
        // Add a new data grid
        this->m_data_grid_name.push_back(datagrid_name);
        this->m_data_grid_size.push_back(0);
    }
    else
    {
        // Show that data grid already exists.
        std::cout << "Warning!!! Datagrid named: " << datagrid_name << " already exists!" << std::endl;
    }
}

unsigned long DataDictionary::Get_CountofDataGrids()
{
    return m_data_grid_name.size();
}

unsigned long DataDictionary::Add_DataGridColumn(std::string data_grid_name, std::string data_column_header)
{

    unsigned long found_data_grid_index = Get_Data_Grid_Index(data_grid_name);

    //ensure that this Data Grid exists
    if (found_data_grid_index != -1) {
        bool check = Ensure_MaxDataColumnHeaderDataGridIndexValid(data_grid_name, found_data_grid_index);
        //ensure that data_column_header exists
        unsigned long found_column_header = false;
        for (unsigned long i = 0; i < m_data_grid_name.size(); i++) {
            if (m_data_column_header[i].Get_ColumnHeader() == data_column_header) {
                found_column_header = i;
                unsigned long capacity = this->m_data_grid_column[found_data_grid_index].capacity();
                unsigned long currsize = this->m_data_grid_column[found_data_grid_index].size();

                if ((capacity - currsize <= 1))
                {
                    this->m_data_grid_column[found_data_grid_index].resize(currsize+1);
                }
                m_data_grid_column[found_data_grid_index].push_back(found_column_header);
                m_data_grid_size[found_data_grid_index] += 1;
                std::cout << "Datagrid name: " << data_grid_name << "  Column name: " << data_column_header << " added successfully." << std::endl;
            }
        }
    }
    else
    {
        Display_DataGridNotFound(data_grid_name);
    }

}

unsigned long DataDictionary::Add_Column(DataColumnHeader* dch)
{
    if (!m_is_full )
    {
        unsigned long found = -1;
        if (m_data_dictionary_size > 0)
        {
            found = Get_DataColumnHeaderIndex(dch->Get_ColumnHeader());
            if (found == -1) {
                Add_ColumnNow(dch);
            } else {
                std::cout << "Warning!!! -- The DataColumn already exists; No column added." << std::endl;
            }
        }
        else
        {
            Add_ColumnNow(dch);
        }
        if (this->m_data_dictionary_size == -1) {
            m_is_full = true;
            std::cout << "Warning!!! -- The DataDictionary just became full."  << std::endl;
        }
    }
    else
    {
        std::cout << "Warning!!! -- The DataDictionary is already full; No column added."  << std::endl;
    }

    return this->m_data_dictionary_size;
}

unsigned long DataDictionary::Get_Size()
{
    return this->m_data_dictionary_size;
}

unsigned long DataDictionary::Get_Size(std::string data_grid_name)
{
    unsigned long size = -1;

    if (!m_data_grid_column.empty())
    {
        unsigned long found = Get_Data_Grid_Index(data_grid_name);
        if (found != -1)
        {
            std::vector<unsigned long> row;
            row = m_data_grid_column.at(found);
            size = static_cast<unsigned long>(m_data_grid_size[found]);
        } else {
            Display_DataGridNotFound(data_grid_name);
        }
    }
    else
    {
        void Show_DataGridsEmpty();
    }
    return size;
}

void DataDictionary::Show_Exception(const __exception e)
{
    std::cout << "Name: " << e.name << "Type: " << e.type << "Arg1: " << e.arg1 << "Arg2: " << e.arg2 << std::endl;
}

void DataDictionary::Display_Address(unsigned long i)
{
    std::cout << "  Column Address: ";  m_data_column_header[i].Display_Address();
}










