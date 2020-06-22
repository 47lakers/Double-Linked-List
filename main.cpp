//
//  main.cpp
//  Double Linked List
//
//  Created by Ira Xavier Porchia on 5/9/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;

class node{
    friend class Double;
private:
    int _data;
    node *_next;
    node *_prev;
public:
    node(int data):
    _data(data),
    _next(nullptr),
    _prev(nullptr){}
};

class Double{
private:
    node *_head;
public:
    Double():
    _head(nullptr){}
    
    ~Double(){
        clear();
    }
    
    void clear(){
        node *p;
        while(_head != nullptr){
            p = _head;
            _head = _head->_next;
            if(_head != nullptr){
            _head->_prev = nullptr;
            }
            p->_next = nullptr;
            p->_prev = nullptr;
            delete p;
        }
    }
    
    void prepend(int data){
        node *temp = new node(data);
        if(_head == nullptr){
            _head = temp;
            return;
        }
        temp->_next = _head;
        _head->_prev = temp;
        _head = temp;
    }
    
    void traverse(){
        node *p = _head;
        while(p != nullptr){
            cout << p->_data << " ";
            p = p->_next;
        }
        cout << endl;
    }
    
    void head(){
        cout << _head->_data << endl;
    }
    
    void append(int data){
        node *temp = new node(data);
        node *p = _head;
        if(_head == nullptr){
            _head = temp;
            return;
        }
        while(p->_next != nullptr){
            p = p->_next;
        }
        p->_next = temp;
        temp->_prev = p;
    }
    
    void remove(int data){
        node *p = _head;
        if(_head == nullptr){
            return;
        }
        if(_head->_data == data){
            _head = _head->_next;
            _head->_prev->_next = nullptr;
            _head->_prev = nullptr;
            return;
        }
        while(p!= nullptr){
            if(p->_data == data){
                if(p->_next == nullptr){
                    p->_prev->_next = nullptr;
                    p->_prev = nullptr;
                    return;
                }
                p->_next->_prev = p->_prev;
                p->_prev->_next = p->_next;
                p->_next = nullptr;
                p->_prev = nullptr;
            }
            p = p->_next;
        }
    }
    
};

int main(int argc, const char * argv[]) {
       Double list;
        list.prepend(50);
        list.prepend(100);
        list.prepend(150);
        list.prepend(200);
        list.prepend(250);
        list.prepend(300);
        list.prepend(350);
        list.prepend(400);
        list.prepend(450);
        list.append(5);
        list.append(10);
        list.append(15);
        list.append(20);
        list.append(25);
        list.append(35);
        list.append(40);
        list.append(45);
        list.traverse();
        list.head();
        list.remove(45);
        list.traverse();
        list.head();
        return 0;
}
