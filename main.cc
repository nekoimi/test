//
// Created by nekoimi on 2021/3/16.
//
#include <ctime>
#include <iostream>
#include <exception>
#include <vector>
#include "ci_helloworld.h"
#include "ci_maximum_subarray.h"
#include "ci_length_of_last_word.h"
#include "ci_plus_one.h"
#include "ci_add_binary.h"
#include "ci_sqrtx.h"
#include "ci_number_of_bites.h"
#include "ci_single_number.h"
#include "ci_quick_sort.h"
#include "ci_queue.h"
#include "ci_kth_node.h"
#include "ci_binary_tree.h"
#include "get_link_node_end.h"
#include "delete_middle_node.h"
#include "merge_two_sorted_link_list.h"
#include "palindrome_linked_list.h"
#include "delete_current_node.h"
#include "intersect_node_for_two_linked_list.h"
#include "covert_linked_to_number.h"
#include "remove_duplicates_node.h"
#include "swap_linked_node.h"
#include "partition_list.h"
#include "reverse_list_by_between.h"

using namespace std;

#define DEBUG 1

#ifdef DEBUG

#endif

class Box {
public:
    virtual double getV() = 0;

protected:
    int width;
    int height;

    int getW() {
        return width;
    }

    int getH() {
        return height;
    }
};

class SmallBox : public Box {
public:
    double getV() {
        return (getW() + getH()) * 2;
    }

    SmallBox(int w, int h) {
        this->width = w;
        this->height = h;
        cout << "构造函数" << endl;
    }

    ~SmallBox() {
        cout << "析构函数" << endl;
    }
};


class MyException : public exception {
    const char *what() const noexcept {
        return "MyException";
    }
};

namespace FirstSpace {
    void showSomeThing() {
        cout << "show some thing" << endl;
    }
}

template<typename T>
inline T const &Max(T const &a, T const &b) {
    return a < b ? a : b;
}

template<class T>
class TemplateClass {
};

// 泛型 Stack<T>

template<class T>
class Stack {
private:
    vector<T> items;
public:
    void push(T const &);

    T pop();

    bool empty() const {
        return items.empty();
    }
};

template<class T>
void Stack<T>::push(T const &item) {
    items.push_back(item);
}

template<class T>
T Stack<T>::pop() {
    if (items.empty()) {
        throw out_of_range("Stack<T>::pop Stack<T> is empty!");
    }

    return items.back();
}

int main() {
    // hello_world();

    // maximum_subarray();
    // length_of_last_word();
    // plus_one();
    // add_binary();
    // sqrtx();
    // number_of_bytes();
    // single_number();
    // quick_do();
    // queue_main();
    // reverse_do();
    // kth_node();
    // binary_tree();
    // getLinkListNodeEnd();
    // delete_middle_node();

//    time_t t = time(0);
//    tm *_tm = localtime(&t);
//    cout << 1900 + _tm->tm_year << endl;
//
//    SmallBox *smallBox = new SmallBox(100, 100);
//    try {
//        smallBox->getV();
//    } catch (out_of_range) {
//
//    }
//    delete smallBox;
//
//    double *privateValue = NULL;
//    privateValue = new double;
//    *privateValue = 3.14;
//
//
//    FirstSpace::showSomeThing();
//
//    cout << "Max(1, 2)" << Max(1, 2) << endl;
//    cout << "Max(1.5, 2.5)" << Max(1.5, 2.5) << endl;
//    cout << "Max('hello', 'world')" << Max("Hello", "World") << endl;
//
//    Stack<int> intStack;
//    Stack<string> stringStack;
//    intStack.push(3);
//    intStack.push(2);
//    intStack.push(1);
//
//    stringStack.push("Nationality");
//    stringStack.push("国际");
//    stringStack.push("Land");
//    stringStack.push("陆地");
//    stringStack.push("HomeLand");
//    stringStack.push("祖国；家乡");
//
//    intStack.pop();
//    stringStack.pop();
//
//    cout << endl;
//    cout << "__FILE__ => " << __FILE__ << endl;
//    cout << "__LINE__ => " << __LINE__ << endl;
//    cout << "__DATE__ => " << __DATE__ << endl;
//    cout << "__TIME__ => " << __TIME__ << endl;
//
//    runIsPalindrome();
//    runDeleteNode();
//    runIntersectLinkedList();
//    runCovertLinkedToNumber();
//    runRemoveDuplicatesNode();
//    runSwapLinkedNode();
//    runPartitionList();
    runReverseListByBetween();

    return 0;
}