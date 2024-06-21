struct NodeHash {
        size_t operator()(const Node* node) const {
                return std::hash<uintptr_t>()(reinterpret_cast<uintptr_t>(node));
        }
};

class Solution {
public:
        Node* copyRandomList(Node* head) {
                Node* header = new Node(0);
                header->next = head;
                Node* new_header = new Node(0);
                Node* tracker = new_header;

                unordered_map<Node*, Node*, NodeHash> myMap;
                Node* tmp = nullptr;

                while (head) {

                        // 添加next节点， 此时对应next的点为head
                        if (myMap.find(head) == myMap.end()) {
                                tracker->next = new Node(head->val);
                                myMap[head] = tracker->next;
                        }
                        else {
                                tracker->next = myMap[head];
                        }

                        // 更新 random
                        if (head->random) {

                                if (myMap.find(head->random) != myMap.end()) {
                                        // 添加random节点，如果map里保存了这个点， 那么就直接取出来更新
                                        tracker->next->random = myMap[head->random];
                                }
                                else {
                                        // 没找到对应点, 预先构造这个点并存入map中
                                        tmp = new Node(head->random->val);
                                        tracker->next->random = tmp;
                                        myMap[head->random] = tmp;
                                }
                        }

                        head = head->next;
                        tracker = tracker->next;
                }

                return new_header->next;   
        }
};