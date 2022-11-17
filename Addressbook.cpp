#include <iostream>
#include <string>
using namespace std;

//定义通讯录：
#define Max_size 1000
struct Person //联系人结构体
{
    string Name;
    string Sex;
    int Age;
    string Phone;
    string Address;
};
struct Addressbook //通讯录结构体
{
    struct Person personArray[Max_size];
    int Size = 0;
};

//函数实现区域：
//菜单界面
void Show_menu()
{
    cout << "######1.添加联系人######" << endl;
    cout << "######2.显示联系人######" << endl;
    cout << "######3.查找联系人######" << endl;
    cout << "######4.删除联系人######" << endl;
    cout << "######5.修改联系人######" << endl;
    cout << "######6.清空联系人######" << endl;
    cout << "######0.退出该系统######" << endl;
}
//添加联系人：
void Addpreson(Addressbook *abs)
{
    if (abs->Size == Max_size)
    {
        cout << "通讯录已满！！！" << endl;
        return;
    }
    else
    {
        //添加联系人姓名：
        string name;
        cout << "请输入联系人姓名：" << endl;
        cin >> name;
        abs->personArray[abs->Size].Name = name;
        //添加联系人性别：
        string sex;
        cout << "请输入联系人性别：" << endl;
        cin >> sex;
        abs->personArray[abs->Size].Sex = sex;
        //添加联系人年龄：
        int age;
        cout << "请输入联系人年龄：" << endl;
        cin >> age;
        abs->personArray[abs->Size].Age = age;
        //添加联系人号码：
        string phone;
        cout << "请输入联系人号码：" << endl;
        cin >> phone;
        abs->personArray[abs->Size].Phone = phone;
        //添加联系人地址：
        string address;
        cout << "请输入联系人地址：" << endl;
        cin >> address;
        abs->personArray[abs->Size].Address = address;
        abs->Size++;
        cout << "添加成功！！！" << endl;
    }
}
//显示联系人：
void Showperson(Addressbook *abs)
{
    if (abs->Size == 0)
    {
        cout << "通讯录为空，请添加联系人！！！" << endl;
    }
    else
    {
        for (int i = 0; i < abs->Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].Name
                 << "   "
                 << "性别: " << abs->personArray[i].Sex
                 << "   "
                 << "年龄：" << abs->personArray[i].Age
                 << "   "
                 << "号码：" << abs->personArray[i].Phone
                 << "   "
                 << "地址：" << abs->personArray[i].Address << endl;
        }
    }
}
//检测联系人是否存在（通用函数，通用于查找，删除，修改）：
int IsExit(Addressbook *abs, string name)
{
    for (int i = 0; i < abs->Size; i++)
    {
        if (abs->personArray[i].Name == name)
        {
            return i;
        }
    }
    return -1;
}
//查找联系人：
void Findperson(Addressbook *abs)
{
    cout << "请输入要查找的联系人姓名：" << endl;
    string name;
    cin >> name;
    int ret = IsExit(abs, name);
    if (ret != -1)
    {
        cout << "查找成功 信息如下：" << endl;
        cout << "姓名： " << abs->personArray[ret].Name
             << "   "
             << "性别： " << abs->personArray[ret].Sex
             << "   "
             << "年龄： " << abs->personArray[ret].Age
             << "   "
             << "号码： " << abs->personArray[ret].Phone
             << "   "
             << "地址： " << abs->personArray[ret].Address << endl;
    }
    else
    {
        cout << "查无此人！！！" << endl;
    }
}
//删除联系人：
void Deleteperson(Addressbook *abs)
{
    cout << "请输入要删除的联系人姓名：" << endl;
    string name;
    cin >> name;
    int ret = IsExit(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->Size--;
        cout << "删除成功！！！" << endl;
    }
    else
    {
        cout << "查无此人！！！" << endl;
    }
}
//修改联系人：
void Modifyperson(Addressbook *abs)
{
    cout << "请输入要修改的联系人姓名：" << endl;
    string name;
    cin >> name;
    int ret = IsExit(abs, name);
    if (ret != -1)
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].Name = name;
        string sex;
        cout << "请输入性别：" << endl;
        cin >> sex;
        abs->personArray[ret].Sex = sex;
        int age;
        cout << "请输入年龄：" << endl;
        cin >> age;
        abs->personArray[ret].Age = age;
        string phone;
        cout << "请输入电话：" << endl;
        cin >> phone;
        abs->personArray[ret].Phone = phone;
        string address;
        cout << "请输入地址：" << endl;
        cin >> address;
        abs->personArray[ret].Address = address;
        cout << "修改成功！！！" << endl;
    }
    else
    {
        cout << "查无此人！！！" << endl;
    }
}
//清空通讯录：
void Clearperson(Addressbook *abs)
{
    abs->Size = 0;
    cout << "通讯录已为空！！！" << endl;
    system("pause");
}

int main()
{
    Addressbook abs;
    int select = 0;
    while (true) //用 do-while 循环更好一点
    {            //可见vs-2022-progect-3的代码
        Show_menu();
        cin >> select;
        switch (select)
        {
        case 1: // 1.添加联系人
            Addpreson(&abs);
            break;
        case 2: // 2.显示联系人
            Showperson(&abs);
            break;
        case 3: // 3.查找联系人
            Findperson(&abs);
            break;
        case 4: // 4.删除联系人
            Deleteperson(&abs);
            break;
        case 5: // 5.修改联系人
            Modifyperson(&abs);
            break;
        case 6: // 6.清空联系人
            Clearperson(&abs);
            break;
        case 0: // 0.退出该系统
            cout << "欢迎下次使用! ! !" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "选择错误！！！" << endl;
            system("pause");
            return 0;
            break;
        }
    }
    system("pause");
    return 0;
}
