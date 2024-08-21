#include <bits/stdc++.h>
using namespace std;
#define FIRST_ZONE 1
#define SECOND_ZONE 2
#define THIRD_ZONE 3
struct Time
{
    int hour;
    int minutes;
};
struct Day
{
    string day_name;
    int firstp_is_empty;
    int secondp_is_empty;
    int thirdp_is_empty;
};
struct Teacher
{
    string name;
    vector<Day> days;
    vector<string> lessons;
    int days_available;
};
struct Lessons
{
    string name;
    string day1;
    string day2;
    Time from;
    Time to;
};
struct Class
{
    string teacher_name;
    string lesson_name;
    string first_day;
    string second_day;
    int which_time_zone;
    int days_available;
};

vector<Teacher> get_teachers()
{
    int num = 0;
    cin >> num;
    cin >> ws;
    vector<Teacher> teachers(num);
    for (int i = 0; i < num; i++)
    {
        int j = 0;
        string str;
        getline(cin, str);
        stringstream line(str);
        vector<string> temp(1);
        while (line >> temp.at(j))
        {
            temp.push_back(" ");
            j++;
        }
        temp.pop_back();
        teachers[i].name = temp[0];
        int num_of_days = stoi(temp[1]);
        teachers.at(i).days_available = num_of_days;
        int l = 2;
        for (int k = 0; k < num_of_days; k++, l++)
        {
            ((teachers.at(i)).days).push_back({temp[l]});
        }
        for (int b = 0; b < num_of_days; b++)
        {
            // all days are empty at first.
            teachers.at(i).days.at(b).firstp_is_empty = 1;
            teachers.at(i).days.at(b).secondp_is_empty = 1;
            teachers.at(i).days.at(b).thirdp_is_empty = 1;
        }
        int num_of_lessons = stoi(temp[l]);
        l++;
        for (int m = 0; m < num_of_lessons; m++, l++)
        {
            (teachers.at(i)).lessons.push_back(temp[l]);
        }
    }
    return teachers;
}

vector<Lessons> get_lessons()
{
    int num = 0;
    cin >> num;
    cin >> ws;
    vector<Lessons> lessons(num);
    for (int i = 0; i < num; i++)
    {
        int j = 0;
        string str;
        getline(cin, str);
        stringstream line(str);
        vector<string> temp(1);
        while (line >> temp.at(j))
        {
            temp.push_back(" ");
            j++;
        }
        temp.pop_back();
        lessons.at(i).name = temp[0];
        lessons.at(i).day1 = temp[1];
        lessons.at(i).day2 = temp[2];
        lessons.at(i).from.hour = stoi(temp[3].substr(0, 2));
        lessons.at(i).from.minutes = stoi(temp[3].substr(3));
        lessons.at(i).to.hour = stoi(temp[4].substr(0, 2));
        lessons.at(i).to.minutes = stoi(temp[4].substr(3));
    }
    return lessons;
}

bool check_days_existance(string lesson, Teacher teacher, string week_day_1, string week_day_2, int time_zone)
{
    // flag!
    int lesson_not_exist = 1;
    for (int m = 0; m < teacher.lessons.size(); m++)
    {
        if (teacher.lessons.at(m) == lesson)
        {
            lesson_not_exist = 0;
            break;
        }
    }
    if (lesson_not_exist)
        return false;
    for (int i = 0; i < teacher.days.size(); i++)
    {
        if (teacher.days.at(i).day_name == week_day_1)
        {
            for (int j = 0; j < teacher.days.size(); j++)
            {
                if (teacher.days.at(j).day_name == week_day_2)
                {
                    if (time_zone == 1)
                    {
                        if ((teacher.days.at(j).firstp_is_empty) && (teacher.days.at(i).firstp_is_empty))
                            return true;
                        else
                            return false;
                    }
                    else if (time_zone == 2)
                    {
                        if ((teacher.days.at(j).secondp_is_empty) && (teacher.days.at(i).secondp_is_empty))
                            return true;
                        else
                            return false;
                    }
                    else
                    {
                        if ((teacher.days.at(j).thirdp_is_empty) && (teacher.days.at(i).thirdp_is_empty))
                            return true;
                        else
                            return false;
                    }
                }
            }
        }
    }
    // ino havaset bashhheeee!!
    return false;
}

void check_teachers(string lesson, vector<Teacher> teachers, vector<Class> &temp_classes, string week_day_1, string week_day_2, int time_zone)
{
    // eshtebahamo fahmidam!!!!!!!! check nakardam ke oon dars ro oon moalem erae mide ya na!!
    for (int i = 0; i < teachers.size(); i++)
    {
        if (check_days_existance(lesson, teachers.at(i), week_day_1, week_day_2, time_zone))
        {
            temp_classes.push_back({teachers.at(i).name, lesson, week_day_1, week_day_2, time_zone, teachers[i].days_available});
        }
        else
            continue;
    }
}

bool check_time_1(Lessons lesson)
{
    if ((lesson.from.hour == 7 && lesson.from.minutes <= 30) && (lesson.to.hour >= 9))
        return true;
        else if((lesson.from.hour <7) && (lesson.to.hour >= 9))
        return true;
    else
        return false;
}

bool check_time_2(Lessons lesson)
{
    if (lesson.from.hour == 9)
    {
        if ((lesson.from.minutes <= 30) && (lesson.to.hour >= 11))
            return true;
        else
            return false;
    }
    else if ((lesson.from.hour < 9) && (lesson.to.hour >= 11))
        return true;
    else
        return false;
}
bool check_time_3(Lessons lesson)
{
    if (lesson.from.hour == 11)
    {
        if ((lesson.from.minutes <= 30) && (lesson.to.hour >= 13))
            return true;
        else
            return false;
    }
    else if ((lesson.from.hour < 11) && (lesson.to.hour >= 13))
        return true;
    else
        return false;
}

bool link_time(Lessons lesson, int time_zone)
{
    if (time_zone == 1)
        return check_time_1(lesson);
    else if (time_zone == 2)
        return check_time_2(lesson);
    else
        return check_time_3(lesson);
}
void change_schedule(vector<Class> &class_arrange, vector<Teacher> &teachers, Class temp, int time_zone)
{
    for (int i = 0; i < teachers.size(); i++)
    {
        if (teachers.at(i).name == temp.teacher_name)
        {
            for (int j = 0; j < teachers.at(i).days_available; j++)
            {
                // teachers.at(i).days.at(j).day_name="yoooo";
                //  por kardane rooze aval.
                if (teachers.at(i).days.at(j).day_name == temp.first_day)
                {
                    if (time_zone == FIRST_ZONE)
                    {
                        if (!teachers.at(i).days.at(j).firstp_is_empty)
                        {
                            class_arrange.pop_back();
                            return;
                        }
                        else
                            teachers.at(i).days.at(j).firstp_is_empty = 0;
                    }
                    else if (time_zone == SECOND_ZONE)
                    {
                        if (!teachers.at(i).days.at(j).secondp_is_empty)
                        {
                            class_arrange.pop_back();
                            return;
                        }
                        else
                            teachers.at(i).days.at(j).secondp_is_empty = 0;
                    }
                    else
                    {
                        if (!teachers.at(i).days.at(j).thirdp_is_empty)
                        {
                            class_arrange.pop_back();
                            return;
                        }
                        else
                            teachers.at(i).days.at(j).thirdp_is_empty = 0;
                    }
                }
                // por kardane rooze dovom.
                if (teachers.at(i).days.at(j).day_name == temp.second_day)
                {
                    if (time_zone == FIRST_ZONE)
                    {
                        if (!teachers.at(i).days.at(j).firstp_is_empty)
                        {
                            class_arrange.pop_back();
                            return;
                        }
                        else
                            (teachers.at(i).days[j]).firstp_is_empty = 0;
                    }
                    else if (time_zone == SECOND_ZONE)
                    {
                        if (!teachers.at(i).days.at(j).secondp_is_empty)
                        {
                            class_arrange.pop_back();
                            return;
                        }
                        else
                            teachers.at(i).days.at(j).secondp_is_empty = 0;
                    }
                    else
                    {
                        if (!teachers.at(i).days.at(j).thirdp_is_empty)
                        {
                            class_arrange.pop_back();
                            return;
                        }
                        else
                            teachers.at(i).days.at(j).thirdp_is_empty = 0;
                    }
                }
            }
        }
    }
}

void min_days(vector<Class> &temp_classes)
{
    // in moghayese ro zamane debug havaset bashe! momkene eshtebah karde basham!
    for (int i = 0; i < temp_classes.size() - 1; i++)
    {
        if ((temp_classes.at(i).teacher_name != temp_classes.at(i + 1).teacher_name)&&
        temp_classes.at(i).lesson_name==temp_classes.at(i+1).lesson_name)
        {
            if (temp_classes.at(i).days_available < temp_classes.at(i + 1).days_available)
            {
                temp_classes.erase(temp_classes.begin() + i + 1);
                i = -1;
            }
            else if (temp_classes.at(i + 1).days_available < temp_classes.at(i).days_available)
            {
                temp_classes.erase(temp_classes.begin() + (i));
                i = -1;
            }
        }
    }
}

void alph_teacher(vector<Class> &temp_classes)
{
    // Check kon!!
    for (int i = 0; i < temp_classes.size() - 1; i++)
    {
        if ((temp_classes.at(i).teacher_name != temp_classes.at(i + 1).teacher_name)&&
        temp_classes.at(i).lesson_name==temp_classes.at(i+1).lesson_name)
        {
            if (temp_classes.at(i).teacher_name < temp_classes.at(i + 1).teacher_name)
            {
                temp_classes.erase(temp_classes.begin() + i + 1);
                i = -1;
            }
            else if (temp_classes.at(i + 1).teacher_name < temp_classes.at(i).teacher_name)
            {
                temp_classes.erase(temp_classes.begin() + (i));
                i = -1;
            }
        }
    }
}

void alph_lesson(vector<Class> &temp_classes)
{
    // Check kon!!
    for (int i = 0; i < temp_classes.size() - 1; i++)
    {
        if (temp_classes.at(i).lesson_name < temp_classes.at(i + 1).lesson_name)
        {
            temp_classes.erase(temp_classes.begin() + i + 1);
            i = -1;
        }
        else if (temp_classes.at(i + 1).lesson_name < temp_classes.at(i).lesson_name)
        {
            temp_classes.erase(temp_classes.begin() + (i));
            i = -1;
        }
    }
}
void check_day_time_zone(vector<Teacher> &teachers, vector<Lessons> lessons, vector<Class> &class_arrange, string day_name, int time_zone)
{
    // for comparing teachers and lessons.
    vector<Class> temp_classes;
    // check kardane tamame doroos dar yek baze ba tamame moalem ha.
    for (int k = 0; k < lessons.size(); k++)
    {

        if ((lessons[k].day1 == day_name || lessons[k].day2 == day_name) && (link_time(lessons[k], time_zone)))
        {
            check_teachers(lessons[k].name, teachers, temp_classes, lessons[k].day1, lessons[k].day2, time_zone);
        }
    }
    // check kone ke dars bardashte nashode bashe!
    for (int i = 0; i < temp_classes.size(); i++)
    {
        for (int j = 0; j < class_arrange.size(); j++)
        {
            if ((temp_classes.at(i).lesson_name) == (class_arrange.at(j).lesson_name))
            {
                temp_classes.erase(temp_classes.begin() + i);
                i = -1;
                break;
            }
        }
    }
    // tadakhole dars ha.
    for(int a=0;a<temp_classes.size();a++)
    {
        for(int b=0;b<class_arrange.size();b++)
        {
            if(temp_classes.at(a).which_time_zone==class_arrange.at(b).which_time_zone)
            {
                if((temp_classes.at(a).first_day==class_arrange.at(b).first_day)||
                (temp_classes.at(a).first_day==class_arrange.at(b).second_day)||(temp_classes.at(a).second_day==class_arrange.at(b).first_day)
                ||(temp_classes.at(a).second_day==class_arrange.at(b).second_day))
                {
                    temp_classes.erase(temp_classes.begin() + a);
                    a = -1;
                    break;

                }

            }
        }


    }
    // halati ke dar in baze zamani dar in rooz chizi peyda nashode!
    if (temp_classes.size() == 0)
        return;
    // halati ke faghat yek class peyda shode!
    else if (temp_classes.size() == 1)
    {

        class_arrange.push_back(temp_classes.at(0));
        // por kardane in bazeye zamani baraye moalem.
        change_schedule(class_arrange, teachers, temp_classes.at(0), time_zone);
        return;
    }
    // halati ke bishtar az yek class peyda shde va hame bayad barresi beshan!
    else
    {
        // check kardane avalin shart!
        min_days(temp_classes);
        if (temp_classes.size() == 1)
        {
            class_arrange.push_back(temp_classes.at(0));
            // por kardane in bazeye zamani baraye moalem.
            change_schedule(class_arrange, teachers, temp_classes.at(0), time_zone);
            return;
        }
        // check kardane alphabetical baraye teachers.
        alph_teacher(temp_classes);
        if (temp_classes.size() == 1)
        {
            class_arrange.push_back(temp_classes.at(0));
            // por kardane in bazeye zamani baraye moalem.
            change_schedule(class_arrange, teachers, temp_classes.at(0), time_zone);
            return;
        }
        // check kardane alphabetical baraye dars ha.
        alph_lesson(temp_classes);
        class_arrange.push_back(temp_classes.at(0));
        if (temp_classes.size() == 1){
        // por kardane in bazeye zamani baraye moalem.
        change_schedule(class_arrange, teachers, temp_classes.at(0), time_zone);
        return;
        }
        
    }
}

bool class_is_complete(vector<Class> class_arrange, vector<Lessons> lessons)
{
    if (class_arrange.size() == lessons.size())
        return true;
    else
        return false;
}
vector<Class> arrangement(vector<Teacher> &teachers, vector<Lessons> lessons)
{
    vector<Class> class_arrange;
    // loop for each day in the week.
    for (int i = 0; i < 5; i++)
    {
        // Saturday
        if (i == 0)
        {
            // check kon ke age darsi bardashte shode bood,baresh nadare dige!!!
            check_day_time_zone(teachers, lessons, class_arrange, "Saturday", FIRST_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Saturday", SECOND_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Saturday", THIRD_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
        }
        // Sunday
        if (i == 1)
        {
            check_day_time_zone(teachers, lessons, class_arrange, "Sunday", FIRST_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Sunday", SECOND_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Sunday", THIRD_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
        }
        // Monday
        if (i == 2)
        {
            check_day_time_zone(teachers, lessons, class_arrange, "Monday", FIRST_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Monday", SECOND_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Monday", THIRD_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
        }
        // Tuesday
        if (i == 3)
        {
            check_day_time_zone(teachers, lessons, class_arrange, "Tuesday", FIRST_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Tuesday", SECOND_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Tuesday", THIRD_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
        }
        // Wednesday
        if (i == 4)
        {
            check_day_time_zone(teachers, lessons, class_arrange, "Wednesday", FIRST_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Wednesday", SECOND_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
            check_day_time_zone(teachers, lessons, class_arrange, "Wednesday", THIRD_ZONE);
            if (class_is_complete(class_arrange, lessons))
                return class_arrange;
        }
    }
    return class_arrange;
}
void print_output(vector<Teacher> teachers,vector<Lessons> lessons, vector<Class> first_class,vector<Class> second_class)
{
    vector<string> lessons_names;
    for(int i=0;i<lessons.size();i++)
    {
        lessons_names.push_back(lessons.at(i).name);
    }
    sort(lessons_names.begin(),lessons_names.end());

    for(int j=0;j<lessons_names.size();j++)
    {
        cout << lessons_names.at(j) << endl;
        int fisrt_class_not_found=1;
        int second_class_not_found=1;
        for(int m=0;m<first_class.size();m++)
        {
            if(lessons_names.at(j)==first_class.at(m).lesson_name)
            {
                fisrt_class_not_found=0;
                cout << first_class.at(m).teacher_name << ": ";
                if(first_class.at(m).which_time_zone==1)
                {
                    cout << "07:30 09:00" << endl;
                    break;
                }
                else if(first_class.at(m).which_time_zone==2)
                {
                    cout << "09:30 11:00" << endl;
                    break;
                }
                else
                {
                    cout << "11:30 13:00" << endl;
                    break;
                }
                
            }
        }
        if(fisrt_class_not_found)
        {
            cout << "Not Found" << endl;
        }
        for(int n=0;n<second_class.size();n++)
        {
            if(lessons_names.at(j)==second_class.at(n).lesson_name)
            {
                second_class_not_found=0;
                cout << second_class.at(n).teacher_name << ": ";
                if(second_class.at(n).which_time_zone==1)
                {
                    cout << "07:30 09:00" << endl;
                    break;
                }
                else if(second_class.at(n).which_time_zone==2)
                {
                    cout << "09:30 11:00" << endl;
                    break;
                }
                else
                {
                    cout << "11:30 13:00" << endl;
                    break;
                }
                
            }
        }
        if(second_class_not_found)
        {
            cout << "Not Found" << endl;
        }
    }

}

int main()
{
    vector<Teacher> teachers = get_teachers();
    vector<Lessons> lessons = get_lessons();
    vector<Class> first_class = arrangement(teachers, lessons);
    vector<Class> second_class = arrangement(teachers, lessons);
    print_output(teachers,lessons,first_class,second_class);
    return 0;
}