#ifndef RBTREE_HPP
#define RBTREE_HPP

template<typename KEY, typename U>
class RBTree
{
private:
    RBTree(const RBTree &input) {}
    const RBTree& operator=(const RBTree &input) {}

private:
    enum COLOR {RED, BLACK};

    class RBNode 
    {
    public:
        RBNode()
        {
            right = NULL;
            left = NULL;
            parent = NULL;
        }

        COLOR RB_COLOR;
        RBNode *right;
        RBNode *left;
        RBNode *parent;
        KEY key;
        U data;
    }

public:
    RBTree()
    {
        this->rb_nil = new RBNode();
        this->rb_root = rb_nil;
        this->rb_nil->right = this->rb_root;
        this->rb_nil->left = this->rb_root;
        this->rb_nil->parent = this->rb_root;
        this->rb_nil->RB_COLOR = BLACK;
    }

    ~RBTree()
    {
        clear(rb_root);
        delete rb_nil;
    }

    bool empty()
    {
        return this->rb_root == this->rb_nil
    }

    RBNode* find(KEY key)
    {
        RBNode *index = rb_root;
        while (index != rb_nil)
        {
            if (key < index->key)
            {
                index = index->left;
            }
            else if (key > index->key)
            {
                index = index->right;
            }
            else
            {
                break;
            }
        }
        return index;
    }

    bool Insert(KEY key, U data)
    {
        RBNode *insert_point = rb_nil;
        RBNode *index = rb_root;
        while (index != rb_nil)
        {
            insert_point = index;
            if (key < index->key)
            {
                index = index->left;
            }
            else if (key > index->key)
            {
                index = index->right;
            }
            else
            {
                return false;
            }
        }

        RBNode *insert_node = new RBNode();
        insert_node->key = key;
        insert_node->data = data;
        insert_node->right = rb_nil;
        insert_node->left = rb_nil;
        if (insert_point == rb_nil)
        {
            rb_root = insert_node;
            rb_root->parent = rb_nil;
            rb_nil->left = rb_root;
            rb_nil->right = rb_root;
            rb_nil->parent = rb_root;
        }
        else
        {
            if (key < insert_point->key)
            {
                insert_point->left = insert_node;
            }
            else
            {
                insert_point->right = insert_node;
            }
            insert_node->parent = insert_point;
        }
        
        InsertFixUp(insert_node);
    }

    void InsertFixUp(RBNode *node)
    {
        while (node->parent->RB_COLOR == RED)
        {
            RBNode *uncle = rb_nil;
            if (node->parent == node->parent->parent->right)
            {
                uncle = node->parent->parent->left;
            }
            else
            {
                uncle = node->parent->parent->right;
            }

            if (uncle->RB_COLOR == RED)
            {
                node->parent->parent->RB_COLOR = RED;
                node->parent->RB_COLOR = BLACK;
                uncle->RB_COLOR = BLACK;
                node = node->parent->parent
            }
            else if (uncle->RB_COLOR == BLACK)
            {
            }
        }
    }

private:
    void clear(RBNode *node)
    {
        if (node != rb_nil)
        {
            clear(node->left);
            clear(node->right)
            delete node;
        }
    }

private:
    RBNode *rb_nil;
    RBNode *rb_root;
};

#endif