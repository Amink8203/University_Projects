#include <bits/stdc++.h>
using namespace std;

const string EMPLOYEES_FILE = "/employees.csv";
const string WORKING_HOURS_FILE = "/working_hours.csv";
const string TEAMS_FILE = "/teams.csv";
const string SALARY_CONFIGS_FILE = "/salary_configs.csv";
const string REPORT_SALARIES = "report_salaries";
const string REPORT_EMPLOYEE_SALARY = "report_employee_salary";
const string REPORT_TEAM_SALARY = "report_team_salary";
const string REPORT_TOTAL_HOURS_PER_DAY = "report_total_hours_per_day";
const string REPORT_EMPLOYEE_PER_HOUR = "report_employee_per_hour";
const string SHOW_SALARY_CONFIG = "show_salary_config";
const string UPDATE_SALARY_CONFIG = "update_salary_config";
const string ADD_WORKING_HOURS = "add_working_hours";
const string DELETE_WORKING_HOURS = "delete_working_hours";
const string UPDATE_TEAM_BONUS = "update_team_bonus";
const string FIND_TEAMS_FOR_BONUS = "find_teams_for_bonus";

const int DAYS_OF_MONTH = 30;
const int FIRST_DAY = 1;
const int LAST_DAY = 30;
const float F_DAYS = 30.0;
const int START_DAY_HOUR = 0;
const int END_DAY_HOUR = 24;

struct ReportHours
{
    int start;
    int end;
    float average;
};

vector<string> seperate_commas(string line)
{
    int i = 0;
    istringstream str(line);
    vector<string> temp(1);
    while (getline(str, temp.at(i), ','))
    {
        temp.push_back(" ");
        i++;
    }
    temp.pop_back();
    return temp;
}

vector<int> seperate_ids(string line)
{
    int i = 0;
    istringstream str(line);
    vector<string> temp(1);
    vector<int> member_ids;
    while (getline(str, temp.at(i), '$'))
    {
        temp.push_back(" ");
        i++;
    }
    temp.pop_back();
    for (int j = 0; j < temp.size(); j++)
    {
        member_ids.push_back(stoi(temp.at(j)));
    }
    return member_ids;
}
vector<int> seperate_hours(string line)
{
    int i = 0;
    istringstream str(line);
    vector<string> temp(1);
    vector<int> hours;
    while (getline(str, temp.at(i), '-'))
    {
        temp.push_back(" ");
        i++;
    }
    temp.pop_back();
    hours.push_back(stoi(temp.at(0)));
    hours.push_back(stoi(temp.at(1)));
    return hours;
}

vector<int> max_hours_days(map<int, int> day_hours)
{
    vector<int> answers;
    pair<int, int> entryWithMaxValue = make_pair(0, 0);
    map<int, int>::iterator currentEntry;
    for (currentEntry = day_hours.begin(); currentEntry != day_hours.end(); currentEntry++)
    {
        if (currentEntry->second >= entryWithMaxValue.second)
        {
            entryWithMaxValue = make_pair(currentEntry->first, currentEntry->second);
        }
    }
    answers.push_back(entryWithMaxValue.first);
    map<int, int>::iterator currentEntry_2;
    for (currentEntry_2 = day_hours.begin(); currentEntry_2 != day_hours.end(); currentEntry_2++)
    {
        if ((currentEntry_2->second == entryWithMaxValue.second) &&
            (currentEntry_2->first != entryWithMaxValue.first))
        {
            answers.push_back(currentEntry_2->first);
        }
    }
    reverse(answers.begin(), answers.end());
    return answers;
}

int max_value(map<int, int> day_hours)
{
    pair<int, int> entryWithMaxValue = make_pair(0, 0);
    map<int, int>::iterator currentEntry;
    for (currentEntry = day_hours.begin(); currentEntry != day_hours.end(); ++currentEntry)
    {
        if (currentEntry->second >= entryWithMaxValue.second)
        {
            entryWithMaxValue = make_pair(currentEntry->first, currentEntry->second);
        }
    }
    return entryWithMaxValue.second;
}

vector<int> min_hours_days(map<int, int> day_hours)
{
    int max = max_value(day_hours);
    vector<int> answers;
    pair<int, int> entryWithMinValue = make_pair(0, max);
    map<int, int>::iterator currentEntry;
    for (currentEntry = day_hours.begin(); currentEntry != day_hours.end(); ++currentEntry)
    {
        if (currentEntry->second <= entryWithMinValue.second)
        {
            entryWithMinValue = make_pair(currentEntry->first, currentEntry->second);
        }
    }
    answers.push_back(entryWithMinValue.first);
    map<int, int>::iterator currentEntry_2;
    for (currentEntry_2 = day_hours.begin(); currentEntry_2 != day_hours.end(); ++currentEntry_2)
    {
        if ((currentEntry_2->second == entryWithMinValue.second) &&
            (currentEntry_2->first != entryWithMinValue.first))
        {
            answers.push_back(currentEntry_2->first);
        }
    }
    reverse(answers.begin(), answers.end());
    return answers;
}

class Salary
{
public:
    Salary add_salary(Salary *salary, string line)
    {
        vector<string> temp;
        temp = seperate_commas(line);
        level = temp.at(0);
        base_salary = stoi(temp.at(1));
        salary_per_hour = stoi(temp.at(2));
        salary_per_extra_hour = stoi(temp.at(3));
        official_working_hours = stoi(temp.at(4));
        tax_percentage = stoi(temp.at(5));
        return *salary;
    }

    string get_level() { return level; }
    int get_base_salary() { return base_salary; }
    int get_salary_per_hour() { return salary_per_hour; }
    int get_salary_per_extra_hour() { return salary_per_extra_hour; }
    int get_official_working_hours() { return official_working_hours; }
    int get_tax() { return tax_percentage; }

    void set_base_salary(int in_base_salary)
    {
        base_salary = in_base_salary;
    }
    void set_salary_per_hour(int in_salary_per_hour)
    {
        salary_per_hour = in_salary_per_hour;
    }
    void set_salary_per_extra_hour(int in_salary_per_extra_hour)
    {
        salary_per_extra_hour = in_salary_per_extra_hour;
    }
    void set_official_working_hours(int in_official_working_hours)
    {
        official_working_hours = in_official_working_hours;
    }
    void set_tax(int in_tax)
    {
        tax_percentage = in_tax;
    }

private:
    string level;
    int base_salary;
    int salary_per_hour;
    int salary_per_extra_hour;
    int official_working_hours;
    int tax_percentage;
};

class WorkingHours
{
public:
    WorkingHours add_work_h(WorkingHours *work, string line)
    {
        vector<string> temp;
        temp = seperate_commas(line);
        vector<int> temp_hours = seperate_hours(temp.at(2));
        start_hour = temp_hours.at(0);
        end_hour = temp_hours.at(1);
        employee_id = stoi(temp.at(0));
        day = stoi(temp.at(1));
        return *work;
    }

    void set_working_hour(int start, int end, int id, int in_day)
    {
        start_hour = start;
        end_hour = end;
        employee_id = id;
        day = in_day;
    }

    int get_employee_id() { return employee_id; }
    int get_start_hour() { return start_hour; }
    int get_end_hour() { return end_hour; }
    int get_day() { return day; }

private:
    int start_hour;
    int end_hour;
    int employee_id;
    int day;
};

class Employee
{
public:
    Employee add_employee(Employee *emp, string line)
    {
        vector<string> temp;
        temp = seperate_commas(line);
        id = stoi(temp.at(0));
        name = temp.at(1);
        age = stoi(temp.at(2));
        level = temp.at(3);
        team_id = -1;
        earning = 0;
        salary_emp = 0;
        hours = 0;
        return *emp;
    }
    void set_team_id(int team_i) { team_id = team_i; }

    void add_working_hours(WorkingHours *work)
    {
        work_doc.push_back(work);
    }

    void set_the_days()
    {
        for (int i = 0; i < work_doc.size(); i++)
        {
            working_days.insert(work_doc.at(i)->get_day());
        }
    }

    void financial_calculate(Salary salary, int team_bonus, int sum_hours)
    {
        if (sum_hours <= salary.get_official_working_hours())
        {
            salary_emp = (salary.get_base_salary()) + (salary.get_salary_per_hour()) * sum_hours;
            bonus = round(salary_emp * (team_bonus) / 100.0);
            tax = round((salary_emp + bonus) * (salary.get_tax()) / 100.0);
            float earning_f = salary_emp * (team_bonus + 100.0) / 100.0;
            earning_f = earning_f * (100.0 - salary.get_tax()) / 100.0;
            earning = round(earning_f);
        }
        else
        {
            int extra_hours = sum_hours - salary.get_official_working_hours();
            salary_emp = (salary.get_base_salary()) + (salary.get_official_working_hours() * (salary.get_salary_per_hour())) +
                         (extra_hours * salary.get_salary_per_extra_hour());
            bonus = round(salary_emp * (team_bonus) / 100.0);
            tax = round((salary_emp + bonus) * (salary.get_tax()) / 100.0);
            float earning_f = salary_emp * (team_bonus + 100.0) / 100.0;
            earning_f = earning_f * (100.0 - salary.get_tax()) / 100.0;
            earning = round(earning_f);
        }
    }

    void calculate_salary(Salary salary, int team_bonus)
    {
        int sum_hours = 0;
        team_bonus_percentage = team_bonus;
        for (int i = 0; i < work_doc.size(); i++)
        {
            sum_hours += (work_doc.at(i)->get_end_hour()) - (work_doc.at(i)->get_start_hour());
        }
        hours = sum_hours;
        financial_calculate(salary, team_bonus, sum_hours);
    }

    int report_total_hours_per_day(int day)
    {
        int sum = 0;
        for (int i = 0; i < work_doc.size(); i++)
        {
            if (day == work_doc.at(i)->get_day())
            {
                sum += work_doc.at(i)->get_end_hour() - work_doc.at(i)->get_start_hour();
            }
        }
        return sum;
    }

    void add_working_hours(int input_day, int start, int end, vector<Salary *> salaries)
    {
        if (input_day < FIRST_DAY || input_day > LAST_DAY || start >= end || start < START_DAY_HOUR || end > END_DAY_HOUR || start > END_DAY_HOUR || end < START_DAY_HOUR)
        {
            cout << "INVALID ARGUMENTS" << endl;
            return;
        }
        for (int i = 0; i < work_doc.size(); i++)
        {
            if (work_doc.at(i)->get_day() == input_day)
            {
                if ((start == work_doc.at(i)->get_start_hour()) && (end == work_doc.at(i)->get_end_hour()))
                {
                    cout << "INVALID_INTERVAL" << endl;
                    return;
                }
                if ((start >= work_doc.at(i)->get_end_hour()) || (end <= work_doc.at(i)->get_start_hour()))
                {
                    continue;
                }
                else
                {
                    cout << "INVALID_INTERVAL" << endl;
                    return;
                }
            }
        }
        WorkingHours *work = new WorkingHours;
        work->set_working_hour(start, end, id, input_day);
        work_doc.push_back(work);
        if (working_days.find(input_day) == working_days.end())
            working_days.insert(input_day);
        hours = hours + (end - start);
        update_financial_hours(hours, salaries);
        cout << "OK" << endl;
    }

    void update_financial_hours(int new_hours, vector<Salary *> salaries)
    {
        for (int i = 0; i < salaries.size(); i++)
        {
            if (salaries.at(i)->get_level() == level)
            {
                Salary salary = *(salaries.at(i));
                financial_calculate(salary, team_bonus_percentage, new_hours);
            }
        }
    }

    void update_salary(Salary salary)
    {
        financial_calculate(salary, team_bonus_percentage, hours);
    }

    void delete_working_hours(int input_day, vector<Salary *> salaries)
    {
        if (input_day < FIRST_DAY || input_day > LAST_DAY)
        {
            cout << "INVALID_ARGUMENTS" << endl;
            return;
        }
        int deleted_hours = 0;
        for (int i = 0; i < work_doc.size(); i++)
        {
            if (work_doc.at(i)->get_day() == input_day)
            {
                deleted_hours += work_doc.at(i)->get_end_hour() - work_doc.at(i)->get_start_hour();
            }
        }
        hours = hours - deleted_hours;
        update_financial_hours(hours, salaries);
        for (int i = 0; i < work_doc.size(); i++)
        {
            if (work_doc.at(i)->get_day() == input_day)
            {
                work_doc.erase(work_doc.begin() + i);
                i = -1;
            }
        }
        working_days.erase(input_day);
        cout << "OK" << endl;
    }

    void update_team_bonus(int bonus_perc, vector<Salary *> salaries)
    {
        Salary salary;
        for (int i = 0; i < salaries.size(); i++)
        {
            if (salaries.at(i)->get_level() == level)
            {
                salary = *(salaries.at(i));
                break;
            }
        }
        team_bonus_percentage = bonus_perc;
        bonus = round(salary_emp * (team_bonus_percentage) / 100.0);
        tax = round((salary_emp + bonus) * (salary.get_tax()) / 100.0);
        float earning_f = salary_emp * (team_bonus_percentage + 100.0) / 100.0;
        earning_f = earning_f * (100.0 - salary.get_tax()) / 100.0;
        earning = round(earning_f);
    }

    int report_employee_per_hour(int start, int end, int &count)
    {
        for (int i = 0; i < work_doc.size(); i++)
        {
            if ((work_doc.at(i)->get_start_hour() <= start) && (work_doc.at(i)->get_end_hour() >= end))
                count++;
        }
        return count;
    }

    int get_id() { return id; }
    int get_hours() { return hours; }
    int get_salary_emp() { return salary_emp; }
    int get_earning() { return earning; }
    int get_age() { return age; }
    int get_team_id() { return team_id; }
    int get_num_of_days() { return working_days.size(); }
    int get_bonus() { return bonus; }
    int get_tax() { return tax; }
    string get_level() { return level; }
    string get_name() { return name; }

private:
    string name;
    string level;
    int id;
    int age;
    int team_id;
    int earning;                     
    int salary_emp;                  
    int hours;                       
    int bonus;                       
    int tax;                         
    int team_bonus_percentage;       
    vector<WorkingHours *> work_doc; 
    set<int> working_days;           
};

class Team
{
public:
    Team add_team(Team *team, string line)
    {
        vector<string> temp;
        temp = seperate_commas(line);
        team_bonus = 0;
        sum_member_hours = 0;
        variance = 0.0;
        team_id = stoi(temp.at(0));
        team_head_id = stoi(temp.at(1));
        member_ids = seperate_ids(temp.at(2));
        bonus_min_working_hours = stoi(temp.at(3));
        bonus_working_hours_max_variance = stof(temp.at(4));
        sort(member_ids.begin(), member_ids.end());
        return *team;
    }

    string find_head_name(vector<Employee *> employees)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            if (team_head_id == employees.at(i)->get_id())
                return employees.at(i)->get_name();
        }
        return "";
    }

    int find_sum_of_members_wh(vector<Employee *> employees)
    {
        int sum = 0;
        for (int i = 0; i < employees.size(); i++)
        {
            for (int j = 0; j < member_ids.size(); j++)
            {
                if (member_ids.at(j) == employees.at(i)->get_id())
                {
                    sum += employees.at(i)->get_hours();
                }
            }
        }
        return sum;
    }

    float find_average_hours(int sum)
    {
        float temp = (double)sum / (double)member_ids.size();
        return temp;
    }

    void show_member_info(vector<Employee *> employees)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            for (int j = 0; j < member_ids.size(); j++)
            {
                if (member_ids.at(j) == employees.at(i)->get_id())
                {
                    cout << "Member ID: " << member_ids.at(j) << endl;
                    cout << "Total Earning: " << employees.at(i)->get_earning() << endl;
                    cout << "---" << endl;
                }
            }
        }
    }

    void update_team_bonus(int in_bonus, vector<Employee *> employees, vector<Salary *> salaries)
    {
        team_bonus = in_bonus;
        for (int i = 0; i < employees.size(); i++)
        {
            if(employees.at(i)->get_team_id() == team_id)
            employees.at(i)->update_team_bonus(in_bonus, salaries);
        }
    }

    void calculate_sum(vector<Employee *> employees)
    {
        for (int j = 0; j < member_ids.size(); j++)
        {
            for (int i = 0; i < employees.size(); i++)
            {
                if (member_ids.at(j) == employees.at(i)->get_id())
                {
                sum_member_hours = sum_member_hours + employees.at(i)->get_hours();
                break;
                }
            }
        }
    }

    void calculate_variance(vector<Employee *> employees)
    {
        int id_size = member_ids.size();
        double mean = static_cast<double> (sum_member_hours) / static_cast<double> (id_size);
        vector<double> temp;
        for (int j = 0; j < member_ids.size(); j++)
        {
            for (int i = 0; i < employees.size(); i++)
            {
                if (member_ids.at(j) == employees.at(i)->get_id())
                {
                int hours = employees.at(i)->get_hours(); 
                temp.push_back(static_cast<double>(hours) - static_cast<double> (mean));
                break;
                }
            }
        }
        double sum = 0.0;
        
        for(int j=0; j<temp.size(); j++)
        {
            sum = sum + ((temp.at(j)) * (temp.at(j)));
        }
        variance = sum / (static_cast<double> (member_ids.size()));
    }

    int get_team_size() { return member_ids.size(); }
    int get_team_id() { return team_id; }
    int get_bonus() { return team_bonus; }
    int get_head_id() { return team_head_id; }
    int get_sum_member_hours() { return sum_member_hours; }
    int get_bonus_min_working_hours() { return bonus_min_working_hours; }
    float get_variance() { return variance; }
    float get_bonus_working_hours_max_variance() { return bonus_working_hours_max_variance; }
    vector<int> get_ids() { return member_ids; }

private:
    int team_id;
    int team_head_id;
    int team_bonus;
    int bonus_min_working_hours;
    int sum_member_hours;
    float bonus_working_hours_max_variance;
    float variance;
    vector<int> member_ids;
};

class Handle
{
public:
    void add_employees(string filename, string arg)
    {
        arg += filename;
        ifstream emp_file(arg);
        string line;
        getline(emp_file, line);
        while (getline(emp_file, line))
        {
            employees.push_back(read_employees(line));
        }
        sort(employees.begin(), employees.end(), [](Employee *e1, Employee *e2)
             { return e1->get_id() < e2->get_id(); });
    }

    void add_teams(string filename, string arg)
    {
        arg += filename;
        ifstream team_file(arg);
        string line;
        getline(team_file, line);
        while (getline(team_file, line))
        {
            teams.push_back(read_teams(line));
        }
        sort(teams.begin(), teams.end(), [](Team *e1, Team *e2)
             { return e1->get_team_id() < e2->get_team_id(); });
        match_team_id_to_members();
    }

    void add_salaries(string filename, string arg)
    {
        arg += filename;
        ifstream salary_file(arg);
        string line;
        getline(salary_file, line);
        while (getline(salary_file, line))
        {
            salaries.push_back(read_salaries(line));
        }
    }

    void add_working_hours(string filename, string arg)
    {
        arg += filename;
        ifstream work_file(arg);
        string line;
        WorkingHours work;
        getline(work_file, line);
        while (getline(work_file, line))
        {
            work_h.push_back(read_working_hours(line));
        }
        match_working_hours();
        emp_salary();
    }

    void set_the_days(Employee &emp)
    {
        emp.set_the_days();
    }
    void match_team_id_to_members()
    {
        for (int i = 0; i < employees.size(); i++)
        {
            for (int j = 0; j < teams.size(); j++)
            {
                for (int k = 0; k < teams.at(j)->get_team_size(); k++)
                {
                    vector<int> temp = teams.at(j)->get_ids();
                    if (employees.at(i)->get_id() == temp.at(k))
                    {
                        employees.at(i)->set_team_id(teams.at(j)->get_team_id());
                    }
                }
            }
        }
    }

    void calculate_salary(Employee &emp, Salary salary, int team_bonus)
    {
        emp.calculate_salary(salary, team_bonus);
    }

    int match_team_bonus(Employee *emp)
    {
        for (int i = 0; i < teams.size(); i++)
        {
            vector<int> temp = teams.at(i)->get_ids();
            for (int j = 0; j < teams.at(i)->get_team_size(); j++)
            {
                if (emp->get_id() == temp.at(j))
                {
                    return teams.at(i)->get_bonus();
                }
            }
        }
        return 0;
    }

    void report_salaries()
    {
        for (int i = 0; i < employees.size(); i++)
        {
            cout << "ID: " << employees.at(i)->get_id() << endl;
            cout << "Name: " << employees.at(i)->get_name() << endl;
            cout << "Total Working Hours: " << employees.at(i)->get_hours() << endl;
            cout << "Total Earning: " << employees.at(i)->get_earning() << endl;
            cout << "---" << endl;
        }
    }
    void report_employee_salary(int emp_id)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            if (emp_id == employees.at(i)->get_id())
            {
                cout << "ID: " << employees.at(i)->get_id() << endl;
                cout << "Name: " << employees.at(i)->get_name() << endl;
                cout << "Age: " << employees.at(i)->get_age() << endl;
                cout << "Level: " << employees.at(i)->get_level() << endl;
                if (employees.at(i)->get_team_id() == -1)
                {
                    cout << "Team ID: N/A" << endl;
                }
                else
                {
                    cout << "Team ID: " << employees.at(i)->get_team_id() << endl;
                }
                cout << "Total Working Hours: " << employees.at(i)->get_hours() << endl;
                cout << "Absent Days: " << DAYS_OF_MONTH - employees.at(i)->get_num_of_days() << endl;
                cout << "Salary: " << employees.at(i)->get_salary_emp() << endl;
                cout << "Bonus: " << employees.at(i)->get_bonus() << endl;
                cout << "Tax: " << employees.at(i)->get_tax() << endl;
                cout << "Total Earning: " << employees.at(i)->get_earning() << endl;
                return;
            }
        }
        cout << "EMPLOYEE_NOT_FOUND" << endl;
    }
    
    void report_team_salary(int id)
    {
        Team team;
        if (!find_team_by_id(teams, team, id))
        {
            cout << "TEAM_NOT_FOUND" << endl;
            return;
        }
        cout << "ID: " << id << endl;
        cout << "Head ID: " << team.get_head_id() << endl;
        cout << "Head Name: " << team.find_head_name(employees) << endl;
        cout << "Team Total Working Hours: " << team.find_sum_of_members_wh(employees) << endl;
        cout << "Average Member Working Hours: ";
        float average = team.find_average_hours(team.find_sum_of_members_wh(employees));
        cout << fixed << setprecision(1) << average;
        cout << endl;
        cout << "Bonus: " << team.get_bonus() << endl;
        cout << "---" << endl;
        team.show_member_info(employees);
    }

    void report_total_hours_per_day(int start_day, int end_day)
    {
        if ((start_day < FIRST_DAY) || (end_day > LAST_DAY) || end_day < start_day)
        {
            cout << "INVALID_ARGUMENTS" << endl;
            return;
        }
        map<int, int> day_hours;
        for (int i = start_day; i <= end_day; i++)
        {
            int sum = 0;
            for (int j = 0; j < employees.size(); j++)
            {
                sum += employees.at(j)->report_total_hours_per_day(i);
            }
            day_hours.insert(pair<int, int>(i, sum));
        }
        for (int i = start_day; i <= end_day; i++)
        {
            cout << "Day #" << i << ": " << day_hours.at(i) << endl;
        }
        cout << "---" << endl;
        vector<int> max_days;
        vector<int> min_days;
        max_days = max_hours_days(day_hours);
        min_days = min_hours_days(day_hours);
        cout << "Day(s) with Max Working Hours: ";
        for (int i = 0; i < max_days.size(); i++)
        {
            if (i == max_days.size() - 1)
            {
                cout << max_days.at(i) << endl;
                break;
            }
            cout << max_days.at(i) << " ";
        }
        cout << "Day(s) with Min Working Hours: ";
        for (int i = 0; i < min_days.size(); i++)
        {
            if (i == min_days.size() - 1)
            {
                cout << min_days.at(i) << endl;
                break;
            }
            cout << min_days.at(i) << " ";
        }
    }

    void report_employee_per_hour(int start_hour, int end_hour)
    {
        if (start_hour < START_DAY_HOUR || start_hour > END_DAY_HOUR || end_hour < START_DAY_HOUR || end_hour > END_DAY_HOUR || start_hour >= end_hour)
        {
            cout << "INVALID_ARGUMENTS" << endl;
            return;
        }
        vector<ReportHours> hours_doc;
        for (int i = start_hour; i < end_hour; i++)
        {
            int sum = 0;
            for (int j = 0; j < employees.size(); j++)
            {
                int count = 0;
                employees.at(j)->report_employee_per_hour(i, i + 1, count);
                sum = sum + count;
            }
            hours_doc.push_back({i, i + 1, sum / F_DAYS});
        }
        sort(hours_doc.begin(), hours_doc.end(), [](ReportHours e1, ReportHours e2) { return e1.start < e2.start; });
        write_report_per_hour(hours_doc);
        cout << "Period(s) with Max Working Employees: ";
        find_max(hours_doc);
        cout << "Period(s) with Min Working Employees: ";
        find_min(hours_doc);
    }

    void write_report_per_hour(vector<ReportHours> &hours_doc)
    {
        for (int i = 0; i < hours_doc.size(); i++)
        {
            hours_doc.at(i).average = round((hours_doc.at(i).average)*10)/10;
            cout << hours_doc.at(i).start << "-" << hours_doc.at(i).end << ": " << hours_doc.at(i).average << endl;
        }
        cout << "---" << endl;
    }

    void show_salary_config(string input_level)
    {
        for (int i = 0; i < salaries.size(); i++)
        {
            if (input_level == salaries.at(i)->get_level())
            {
                cout << "Base Salary: " << salaries.at(i)->get_base_salary() << endl;
                cout << "Salary Per Hour: " << salaries.at(i)->get_salary_per_hour() << endl;
                cout << "Salary Per Extra Hour: " << salaries.at(i)->get_salary_per_extra_hour() << endl;
                cout << "Official Working Hours: " << salaries.at(i)->get_official_working_hours() << endl;
                cout << "Tax: " << salaries.at(i)->get_tax() << "%" << endl;
                return;
            }
        }
        cout << "INVALID_LEVEL" << endl;
    }

    void update_salary_config(string in_level, string in_base_salary, string in_salary_per_hour,
                              string in_salary_per_extra_hour, string in_official_working_hours, string in_tax_percentage)
    {
        if (in_level != "junior" && in_level != "senior" && in_level != "expert" && in_level != "team_lead")
        {
            cout << "INVALID LEVEL" << endl;
            return;
        }
        Salary salary;
        int i = 0;
        for (i; i < salaries.size(); i++)
        {
            if (in_level == salaries.at(i)->get_level())
            {
                if (in_base_salary != "-")
                {
                    salaries.at(i)->set_base_salary(stoi(in_base_salary));
                }
                if (in_salary_per_hour != "-")
                {
                    salaries.at(i)->set_salary_per_hour(stoi(in_salary_per_hour));
                }
                if (in_salary_per_extra_hour != "-")
                {
                    salaries.at(i)->set_salary_per_extra_hour(stoi(in_salary_per_extra_hour));
                }
                if (in_official_working_hours != "-")
                {
                    salaries.at(i)->set_official_working_hours(stoi(in_official_working_hours));
                }
                if (in_tax_percentage != "-")
                {
                    salaries.at(i)->set_tax(stoi(in_tax_percentage));
                }
                salary = *(salaries.at(i));
                break;
            }
        }
        for (int j = 0; j < employees.size(); j++)
        {
            if (employees.at(j)->get_level() == in_level)
            {
                employees.at(j)->update_salary(salary);
            }
        }
        cout << "OK" << endl;
    }
    void add_working_hours(int input_id, int input_day, int start, int end)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees.at(i)->get_id() == input_id)
            {
                employees.at(i)->add_working_hours(input_day, start, end, salaries);
                return;
            }
        }
        cout << "EMPLOYEE_NOT_FOUND" << endl;
    }

    void delete_working_hours(int input_id, int input_day)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees.at(i)->get_id() == input_id)
            {
                employees.at(i)->delete_working_hours(input_day, salaries);
                return;
            }
        }
        cout << "EMPLOYEE_NOT_FOUND" << endl;
    }
    void update_team_bonus(int in_team_id, int in_bonus)
    {
        if (in_bonus < 0 || in_bonus > 100)
        {
            cout << "INVALID_ARGUMENTS" << endl;
            return;
        }
        for (int i = 0; i < teams.size(); i++)
        {
            if (teams.at(i)->get_team_id() == in_team_id)
            {
                teams.at(i)->update_team_bonus(in_bonus, employees, salaries);
                cout << "OK" << endl;
                return;
            }
        }
        cout << "TEAM_NOT_FOUND" << endl;
    }

    void delete_everything()
    {
        for (Employee *employee : employees)
            delete employee;
        for (Salary *salary : salaries)
            delete salary;
        for (Team *team : teams)
            delete team;
        for (WorkingHours *work : work_h)
            delete work;
    }

    void find_teams_for_bonus()
    {
        for (int i = 0; i < teams.size(); i++)
        {
            teams.at(i)->calculate_sum(employees);
            teams.at(i)->calculate_variance(employees);
        }
        vector<Team> for_bonus;
        for (int i = 0; i < teams.size(); i++)
        {
            if((teams.at(i)->get_sum_member_hours() > teams.at(i)->get_bonus_min_working_hours()) &&
            (teams.at(i)->get_variance() < teams.at(i)->get_bonus_working_hours_max_variance()))
            for_bonus.push_back(*(teams.at(i)));
        }
        if(for_bonus.size() == 0)
        cout << "NO_BONUS_TEAMS" << endl;
        sort(for_bonus.begin(), for_bonus.end(), [](Team e1, Team e2) { 
            if(e1.get_sum_member_hours() == e2.get_sum_member_hours())
            return e1.get_team_id() < e2.get_team_id();
            else
            return e1.get_sum_member_hours() < e2.get_sum_member_hours();
            });
        for(int i=0; i<for_bonus.size(); i++)
        {
        cout << "Team ID: " << for_bonus.at(i).get_team_id() << endl;
        }
    }

private:
    vector<Employee *> employees;
    vector<Salary *> salaries;
    vector<Team *> teams;
    vector<WorkingHours *> work_h;

    WorkingHours *read_working_hours(string line)
    {
        WorkingHours *work = new WorkingHours;
        *work = work->add_work_h(work, line);
        return work;
    }

    Employee *read_employees(string line)
    {
        Employee *emp = new Employee;
        *emp = emp->add_employee(emp, line);
        return emp;
    }

    Team *read_teams(string line)
    {
        Team *team = new Team;
        *team = team->add_team(team, line);
        return team;
    }

    Salary *read_salaries(string line)
    {
        Salary *salary = new Salary;
        *salary = salary->add_salary(salary, line);
        return salary;
    }

    float max_average(vector<ReportHours> hours_doc)
    {
        ReportHours max = {0, 0, 0.0};
        for (int i = 0; i < hours_doc.size(); i++)
        {
            if (max.average <= hours_doc.at(i).average)
            {
                max.average = hours_doc.at(i).average;
            }
        }
        return max.average;
    }

    void find_max(vector<ReportHours> hours_doc)
    {
        ReportHours max = {0, 0, 0.0};
        for (int i = 0; i < hours_doc.size(); i++)
        {
            if (max.average <= hours_doc.at(i).average)
            {
                max.start = hours_doc.at(i).start;
                max.end = hours_doc.at(i).end;
                max.average = hours_doc.at(i).average;
            }
        }
        vector<ReportHours> answer;
        for (int i = 0; i < hours_doc.size(); i++)
        {
            if (max.average == hours_doc.at(i).average)
            {
                answer.push_back({hours_doc.at(i).start, hours_doc.at(i).end, hours_doc.at(i).average});
            }
        }
        write_min_max(answer);
    }

    void find_min(vector<ReportHours> hours_doc)
    {
        ReportHours min = {0, 0, max_average(hours_doc)};
        for (int i = 0; i < hours_doc.size(); i++)
        {
            if (min.average >= hours_doc.at(i).average)
            {
                min.start = hours_doc.at(i).start;
                min.end = hours_doc.at(i).end;
                min.average = hours_doc.at(i).average;
            }
        }
        vector<ReportHours> answer;
        for (int i = 0; i < hours_doc.size(); i++)
        {
            if (min.average == hours_doc.at(i).average)
            {
                answer.push_back({hours_doc.at(i).start, hours_doc.at(i).end, hours_doc.at(i).average});
            }
        }
        write_min_max(answer);
    }

    void write_min_max(vector<ReportHours> answer)
    {
        for (int i = 0; i < answer.size(); i++)
        {
            if (i == answer.size() - 1)
            {
                cout << answer.at(i).start << "-" << answer.at(i).end << endl;
                break;
            }
            cout << answer.at(i).start << "-" << answer.at(i).end << " ";
        }
    }

    bool find_team_by_id(vector<Team *> teams, Team &team, int id)
    {
        for (int i = 0; i < teams.size(); i++)
        {
            if (teams.at(i)->get_team_id() == id)
            {
                team = *(teams[i]);
                return true;
            }
        }
        return false;
    }

    void emp_salary()
    {
        for (int i = 0; i < employees.size(); i++)
        {
            for (int j = 0; j < salaries.size(); j++)
            {
                if (employees.at(i)->get_level() == salaries.at(j)->get_level())
                {
                    int team_bonus = 0;
                    team_bonus = match_team_bonus(employees.at(i));
                    calculate_salary(*(employees[i]), *(salaries[j]), team_bonus);
                }
            }
        }
    }
    void match_working_hours()
    {
        for (int i = 0; i < employees.size(); i++)
        {
            for (int j = 0; j < work_h.size(); j++)
            {
                if ((work_h.at(j))->get_employee_id() == (employees.at(i))->get_id())
                {
                    employees.at(i)->add_working_hours(work_h.at(j));
                }
            }
            set_the_days(*(employees[i]));
        }
    }
};

void handle_report_salaries(Handle &handle)
{
    handle.report_salaries();
}

void handle_report_employee_salary(Handle &handle)
{
    int id;
    cin >> id;
    handle.report_employee_salary(id);
}

void handle_report_team_salary(Handle &handle)
{
    int id;
    cin >> id;
    handle.report_team_salary(id);
}

void handle_report_total_hours_per_day(Handle &handle)
{
    int start_day;
    int end_day;
    cin >> start_day >> end_day;
    handle.report_total_hours_per_day(start_day, end_day);
}

void handle_report_employee_per_hour(Handle &handle)
{
    int start_hour;
    int end_hour;
    cin >> start_hour >> end_hour;
    handle.report_employee_per_hour(start_hour, end_hour);
}

void handle_show_salary_config(Handle &handle)
{
    string level;
    cin >> level;
    handle.show_salary_config(level);
}

void handle_update_salary_config(Handle &handle)
{
    string input_level;
    string input_base_salary;
    string input_salary_per_hour;
    string input_salary_per_extra_hour;
    string input_official_working_hours;
    string input_tax_percentage;
    cin >> input_level >> input_base_salary >> input_salary_per_hour >>
        input_salary_per_extra_hour >> input_official_working_hours >> input_tax_percentage;
    handle.update_salary_config(input_level, input_base_salary, input_salary_per_hour,
                                input_salary_per_extra_hour, input_official_working_hours, input_tax_percentage);
}

void handle_add_working_hours(Handle &handle)
{
    int input_id;
    int input_day;
    int start;
    int end;
    cin >> input_id >> input_day >> start >> end;
    handle.add_working_hours(input_id, input_day, start, end);
}

void handle_delete_working_hours(Handle &handle)
{
    int input_id;
    int input_day;
    cin >> input_id >> input_day;
    handle.delete_working_hours(input_id, input_day);
}

void handle_update_team_bonus(Handle &handle)
{
    int in_team_id;
    int in_bonus;
    cin >> in_team_id >> in_bonus;
    handle.update_team_bonus(in_team_id, in_bonus);
}

void handle_find_teams_for_bonus(Handle &handle)
{
    handle.find_teams_for_bonus();
}

int main(int argc, char *argv[])
{
    Handle handle;
    handle.add_employees(EMPLOYEES_FILE, argv[1]);
    handle.add_teams(TEAMS_FILE, argv[1]);
    handle.add_salaries(SALARY_CONFIGS_FILE, argv[1]);
    handle.add_working_hours(WORKING_HOURS_FILE, argv[1]);
    string command;
    while (cin >> command)
    {
        if (command == REPORT_SALARIES)
        {
            handle_report_salaries(handle);
        }
        else if (command == REPORT_EMPLOYEE_SALARY)
        {
            handle_report_employee_salary(handle);
        }
        else if (command == REPORT_TEAM_SALARY)
        {
            handle_report_team_salary(handle);
        }
        else if (command == REPORT_TOTAL_HOURS_PER_DAY)
        {
            handle_report_total_hours_per_day(handle);
        }
        else if (command == REPORT_EMPLOYEE_PER_HOUR)
        {
            handle_report_employee_per_hour(handle);
        }
        else if (command == SHOW_SALARY_CONFIG)
        {
            handle_show_salary_config(handle);
        }
        else if (command == UPDATE_SALARY_CONFIG)
        {
            handle_update_salary_config(handle);
        }
        else if (command == ADD_WORKING_HOURS)
        {
            handle_add_working_hours(handle);
        }
        else if (command == DELETE_WORKING_HOURS)
        {
            handle_delete_working_hours(handle);
        }
        else if (command == UPDATE_TEAM_BONUS)
        {
            handle_update_team_bonus(handle);
        }
        else if (command == FIND_TEAMS_FOR_BONUS)
        {
            handle_find_teams_for_bonus(handle);
        }
    }
    handle.delete_everything();
    return 0;
}