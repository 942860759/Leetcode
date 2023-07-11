// Definition for singly-linked list.
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print_f() {
        std::cout <<  val << std::endl;
        ListNode *tmp = next;
        while (tmp) {
            std::cout <<  tmp->val << std::endl;
            tmp = tmp->next;
        }
    }
};

class Solution {
public:
    ListNode* revertNode(ListNode* l) {
        ListNode* p = l;
        ListNode* n = p->next;
        ListNode* tmp = nullptr;
        p->next = nullptr;
        while (n) {
            tmp = n->next;
            n->next = p;
            p = n;
            n = tmp;
        }
        return p;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* p1 = l1;
            ListNode* p2 = l2;
            ListNode* result = nullptr;
            ListNode* first = nullptr;

            bool isTen = false;
            int addOne = 0;
            int add = 0;
            while (p1 && p2) {
                addOne = 0;
                if (isTen)
                    addOne = 1;
                add = p1->val + p2->val + addOne;
                if (add >= 10)
                    isTen = true;
                else
                    isTen = false;
                if (isTen)
                    add = add - 10;
                ListNode *tmp = new ListNode(add);

                if (first) {
                    first->next = tmp;
                    first = first->next;
                }

                if (result == nullptr) {
                    result = tmp;
                    first = result;
                }

                p1 = p1->next;
                p2 = p2->next;
            }
            if (p1) {
                while (p1) {
                    addOne = 0;
                    if (isTen)
                        addOne = 1;
                    add = p1->val + addOne;
                    if (add >= 10)
                        isTen = true;
                    else
                        isTen = false;
                    if (isTen)
                        add = add - 10;
                    ListNode *tmp = new ListNode(add);
                    if (first) {
                        first->next = tmp;
                        first = first->next;
                    }
                    p1 = p1->next;
                }
            }
            if (p2) {
                while (p2) {
                    addOne = 0;
                    if (isTen)
                        addOne = 1;
                    add = p2->val + addOne;
                    if (add >= 10)
                        isTen = true;
                    else
                        isTen = false;
                    if (isTen)
                        add = add - 10;
                    ListNode *tmp = new ListNode(add);
                    if (first) {
                        first->next = tmp;
                        first = first->next;
                    }
                    p2 = p2->next;
                }
            }
            if (isTen) {
                ListNode *tmp = new ListNode(1);
                first->next = tmp;
            }
            return result;
    }
};

int main() {
    Solution solution;
    ListNode p1 = ListNode(2);
    ListNode p2 = ListNode(4);
    ListNode p3 = ListNode(9);
    ListNode q1 = ListNode(5);
    ListNode q2 = ListNode(6);
    ListNode q3 = ListNode(4);
    ListNode q4 = ListNode(9);
    ListNode* l1 = &p1;
    l1->next = &p2;
    l1->next->next = &p3;
    ListNode* l2 = &q1;
    l2->next = &q2;
    l2->next->next = &q3;
    l2->next->next->next = &q4;

    ListNode* result = solution.addTwoNumbers(l1, l2);
    result->print_f();
    return 0;
}