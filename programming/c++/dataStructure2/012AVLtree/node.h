#ifndef AVLNODE_H
#define AVLNODE_H


class AVLNode{

    private:
        AVLNode* left, *right;
        int data;
        int height;

    public:
        AVLNode();
        AVLNode(int);
        virtual ~AVLNode();
        int getData();
        int getHeight();
        void setData(int);
        void setHeight(int);
        AVLNode* getLeft();
        AVLNode* getRight();
        void setRight(AVLNode*);
        void setLeft(AVLNode*);

};

#endif // AVLNODE_H
