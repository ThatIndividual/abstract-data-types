#ifndef ALG_vklist_h
#define ALG_vklist_h

struct vklist
{
    struct vk_node* sent; /* Sentinel node. It's always in the list. */
    int length;
};

struct vk_node
{
    struct vk_node* next;
    struct vk_node* prev;
    const char* key;
    int value;
};

struct vklist* vklist_new(void);
void vklist_insert(struct vklist*, const char*, int);
int vklist_get(struct vklist*, const char*);
void vklist_print(struct vklist*);

#endif

