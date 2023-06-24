#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class User
{
public:
    string name;
    int age;

    User(string name = "", int age = 0) : name{ name }, age{ age } {};
    string ToString() { return "Name: " + name + ", age: " + to_string(age); }
    friend ostream& operator<<(ostream& out, const User& user)
    {
        out << "Name: " << user.name << ", age: " << to_string(user.age);
    }
};

template <typename Iterator>
void ContainerInit(Iterator begin, Iterator end);
template <typename Iterator>
void ContainerPrint(Iterator begin, Iterator end);

int main()
{
    srand(time(nullptr));
    vector<int> v(10);
    list<int> l(10);

    vector<User> users
    {
        User("Leo", 34),
        User("Bob", 42),
        User("Tom", 25),
    };

    ContainerInit(v.begin(), v.end());
    ContainerInit(l.begin(), l.end());

    ContainerPrint(v.begin(), v.end());
    ContainerPrint(l.begin(), l.end());

    cout << boolalpha <<  all_of(v.begin(), v.end(), [](auto item) 
        {
            return item >= 10;
        }) << "\n";

    cout << boolalpha << all_of(users.begin(), users.end(), [](auto u) 
        {
            return u.age >= 30;
        });
    cout << "\n";

    cout << count(v.begin(), v.end(), 20) << "\n";
    cout << count_if(v.begin(), v.end(), [](auto item) 
        {
            return item > 50;
        }) << "\n";

    vector<int> v1{1, 2, 3, 4, 5, 5, 1, 2, 3, 4, 5 };
    list<int> l1;
    l1.push_back(7);
    l1.push_back(9);

    auto it1 = find_end(v1.begin(), v1.end(), l1.begin(), l1.end());
    ContainerPrint(it1, v1.end());
    cout << distance(v1.begin(), it1) << "\n";

    auto it2 = find_first_of(v1.begin(), v1.end(), l1.begin(), l1.end());
    ContainerPrint(it2, v1.end());
    cout << distance(v1.begin(), it2) << "\n";

    auto it3 = adjacent_find(v1.begin(), v1.end());

    cout << distance(v1.begin(), it3) << "\n";

    //move(l1.begin(), l1.end(), v1.begin() + 3);
    ContainerPrint(v1.begin(), v1.end());
    ContainerPrint(l1.begin(), l1.end());

    transform(l1.begin(), l1.end(), v1.begin() + 2, [](auto item)
        {
            return item * item;
        });
    ContainerPrint(v1.begin(), v1.end());
    ContainerPrint(l1.begin(), l1.end());

    //remove_copy(v1.begin(), v1.end(), l1.begin(), 2);
    //ContainerPrint(v1.begin(), v1.end());
    //ContainerPrint(l1.begin(), l1.end());

    int m = v.size() / 2;
    cout << v[m] << "\n";
    auto it = partition(v.begin(), v.end(), [=](auto item)
        {
            return item < v[m];
        });
    
    ContainerPrint(v.begin(), v.end());
    
    ContainerPrint(it, v.end());
}


template <typename Iterator>
void ContainerInit(Iterator begin, Iterator end)
{
    /*for (begin; begin != end; begin++)
        *begin = rand() % 100;*/
    generate(begin, end, []() 
        {
            return rand() % 100;
        });
}

template <typename Iterator>
void ContainerPrint(Iterator begin, Iterator end)
{
    /*for (begin; begin != end; begin++)
        cout << *begin << " ";
    cout << "\n";*/
    for_each(begin, end, [](auto item)
        {
            cout << item << " ";
        });
    cout << "\n";
}