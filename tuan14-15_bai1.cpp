#include <iostream> 
#include <string.h> 

using namespace std; 

template <class T> class Node 
{ 
public: 
    T value; 
    Node* next; 
    Node(T v) : value(v), next(0) {}; 
}; 

 
template <class T> 
class List 
{ 
    Node<T>* head, * tail; 
    int count; 
public: 
    List() : count(0) { head = 0, tail = 0; } 
    ~List() 
    { 
        delete head; 
        delete tail; 
    }                 

    void RemoveAll() 
    { 
        while (count) 
        { 
            --count; 
            Node<T>* p = this->head; 
            this->head = p->next; 
        } 
    } 
    void add(T v)
    { 
        Node<T>* newNode = new Node<T>(v); 
        if (count++ == 0) 
        { 
           head = newNode; 
           tail = newNode; 
        }
		 
        else 
        { 
            tail->next = newNode; 
            tail = newNode; 
        } 
    } 

    Node<T>* First() const{ 
        return head; 
    } 

    int Count() const
    { 
        return count; 
    } 

    T* ToArray()
    {
        T* arr = new T[count]; 
        Node<T>* p = head; 
        for (int i = 0; i < count; i++, p = p->next) 
        { 
            arr[i] = p->value; 
        } 
        return arr;
    } 
    void remove(int pos) 
    { 
        Node<T>* p = head; 
        int k = 1; 
        if (pos <= 1)
        { 
            Node<T>* tmp = head; 
            head = tmp->next; 
            delete tmp; 
        } 
       else 
        { 
            if (pos > count) 
                pos = count; 
            while (k++ != pos - 1) 
            { 
                p = p->next; 
            } 
            Node<T>* tmp = p->next; 
            p->next = tmp->next; 
            if (pos == count) 
                tail = p; 
            delete tmp; 
        } 
        count--; 
    } 
    void display() 
    { 
        T* arr = this->ToArray(); 
        for (int i = 0; i < count; i++) 
        { 
            cout << "Thong tin nguoi thu " << i + 1 << ": " << endl; 
            arr[i].display(); 
        }
    } 
    void sort() 
    { 
        for (Node<T>* p1 = head; p1 != 0; p1 = p1->next) 
        { 
            for (Node<T>* p2 = p1->next; p2 != 0; p2 = p2->next) 
            {
                if (p1->value.getID() > p2->value.getID()) 
                {
                    T tmp = p1->value; 
                    p1->value = p2->value; 
                    p2->value = tmp; 
                } 
            } 
        }
    }
    void modify(int pos) 
    {
        Node<T>* p = head;
        int k = 1;
        if (pos < 1)
            pos = 1;
        else if (pos > count)
            pos = count;
        while (k++ != pos)
            p = p->next;
        p->value.input();
    }
}; 



class person{ 

private:
    int id;
    string name;
    string gender;
    
public: 
    person(int _id = 0, string _name = "unknown", string _gender = "unknown") 
    { 
        id = _id;
        name = _name;
        gender = _gender;
    }
    
    person(const person& per1) 
    {
        id = per1.id;
        name = per1.name;
        gender = per1.gender;
    } 

    ~person() {};
    void input()
   {
        cout << "Nhap ma dinh danh:";
        cin >> this->id;
        cout << "Nhap ho ten: ";
        cin.ignore(1);
        getline(cin, this->name);
        cout << "Nhap gioi tinh: ";
        getline(cin, this->gender);
    } 

    void display()
    { 
        cout << "Person:" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
    } 

    int getID()
    { 
        return id;
    }
}; 

class student : public person 
{ 

private: 
  int stuID;
  string clas; 

public: 
student(int _id = 0, string _name = "unknown", string _gender = "unknown", int _stuID = 0, string _clas = "unknown") : person(_id, _name, _gender) 
{ 
        stuID = _stuID;
        clas = _clas;
    } 

    void display()
    { 
        person::display();
        cout << "student ID:" << stuID << endl;
        cout << "Class:" << clas << endl;
    }
    void input()
    {
        person::input();
        cout << " Nhap stuID: ";
        cin >> this->stuID;
        cin.ignore(1);
        cout << " Nhap ten lop: ";
        getline(cin, this->clas);
    }
}; 

 

int main()
{ 

    List<student> lofstuds;
    student std1(1, "Chu Van A", "male", 2019001, "ET1-01");
    student std2(2, "Nguyen Thi B", "female", 20190002, "IT1");
    student std3(3, "Tran Van C", "male", 20190003, "ET1-01");
    lofstuds.add(std2);
    lofstuds.add(std3);
    lofstuds.add(std1);
    lofstuds.sort();
    cout << endl << "In danh sach ban dau: " << endl;
    lofstuds.display();
    cout << endl << "Sua doi thong tin student thu 1: " << endl;
    cout << "Nhap thong tin sua doi:" << endl;
    lofstuds.modify(1);
    cout << endl << "Danh sach sau khi sua doi: " << endl;
    lofstuds.display();
    cout << endl << "In danh sach sau khi xoa student thu 2:" << endl;
    lofstuds.remove(2);
    lofstuds.display(); 
    return 0;
} 
