#include<bits/stdc++.h>
using namespace std;
struct newnode //structure for creating a node for graph 
{
int w,src,dest;
struct newnode *next;
};

struct nodelist // structure for creating a adjacency list
{
    struct newnode *head;
    int data;
};

struct Graph // structure for creating a graph
{
    int v;
    struct nodelist *array;
};

struct listnode  //structure for creating a list
{
    int src,dest,w;
    struct listnode* next;
};

struct Graph * creategraph(int v)
{
    struct Graph* graph=( struct Graph*)malloc(sizeof( struct Graph));
    graph->v=v;
    graph->array=(struct nodelist*)malloc(v *sizeof(struct nodelist));
    for(int i=1;i<=v;i++)
    {
        cout<<"Enter the data of "<<i<<"vertex==>";
        cin>>graph->array[i].data;
graph->array[i].head=NULL;
    }
    return graph;
}
struct newnode *newlist(int dest,int s,int w)
{
    struct newnode* newnode1=(newnode*)malloc(sizeof(newnode));
    newnode1->dest=dest;
    newnode1->src=s;
    newnode1->w=w;
    newnode1->next=NULL;
    return newnode1;


}
void addlist(Graph*graph,int s,int d,int w)
{
     struct newnode* check=NULL;
    struct newnode* newnode1=newlist(d,s,w);
    if(graph->array[s].head==NULL)
    {
        newnode1->next=graph->array[s].head;
        graph->array[s].head=newnode1;
    }
    else
    {
        check=graph->array[s].head;
        while(check->next!=NULL)
        {
            check=check->next;
        }
        check->next=newnode1;
    }


}
void print(struct Graph *graph)
{
    int v;
    for(v=1;v<=graph->v;v++)
    {
        cout<<"vertex "<<v<<" having data "<<graph->array[v].data<<" is connected to ";
        struct newnode*p=graph->array[v].head;
        while(p)
        {
            cout<<p->dest<<" node having data "<<"("<<graph->array[p->dest].data<<")"<<" and the edge weight is "<<p->w;
            p=p->next;
        }
        cout<<endl;
    }


}
struct listnode *createlist(Graph *graph)
{
     struct listnode *head=NULL;
     
    int v;
    for(v=1;v<=graph->v;v++)
    {
       
        struct newnode*p=graph->array[v].head;
        while(p)
        {
            listnode*temp=(listnode*)malloc(sizeof(listnode));
             temp->dest=p->dest;
             temp->src=p->src;
             temp->w=p->w;
             temp->next=NULL;
            
                 temp->next=head;
                 head=temp;
            
            p=p->next;
        }
        cout<<endl;
    }

  return head;  
}

void sortlist(listnode *head,listnode *p1,listnode *p2)
{
    if(p2==NULL)
    {
        return;
    }
   listnode *p3=p1->next;
   while(p3!=NULL)
    {
        if(p1->w>p3->w)
        {
            swap(p1->src,p3->src);
            swap(p1->dest,p3->dest);
            swap(p1->w,p3->w);
        }
        p3=p3->next;
    }
    sortlist(head,p2,p2->next);
}
void printlist(listnode*head)
{
    while(head!=NULL)
    {
        cout<<head->src<<" -> "<<head->dest<<"  weight -> "<<head->w<<endl;
        head=head->next;
    }
}
int find(int parent[], int i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return find(parent, parent[i]);
}

void select(Graph *g, listnode *head, int n)
{
    listnode *ptr = head, *ptr1 = NULL;
    int *parent = (int *)malloc(g->v * sizeof(int));
    int i;
    memset(parent, -1, sizeof(int) * g->v);
    for (i = 0; ptr != NULL && i < n;)
    {
        int check1 = find(parent, ptr->src - 1);
        int check2 = find(parent, ptr->dest - 1);
        if (check1 != check2)
        {
            parent[ptr->dest - 1] = ptr->src - 1;
            i++;
        }
        else
        {
            ptr1->next = ptr->next;
            free(ptr);
            ptr = ptr1;
        }
        ptr1 = ptr;
        ptr = ptr->next;
        if (i == n - 1)
            ptr->next = NULL;
    }
}

int main()
{
    int v;
    cin>>v;
    
    struct Graph *graph=creategraph(v);
    while(1)
    {
        int ch,s,d,w;;
        cout<<"ENTER 1 for add connection and 0 for exit";
        scanf("%d",&ch);
        if(ch==0)
        break;
         cout<<"Enter source,destination and weight ";
        cin>>s>>d>>w;
        addlist(graph,s,d,w);
        

    }
    cout<<"GRAPH"<<endl<<endl;
    print(graph);
    struct listnode *head=createlist(graph);// creating a list of connections of a graph
    sortlist(head,head,head->next); // sorting the list to get weight in ascending order

    select(graph,head,v-1);// creating a minimum spanning tree
    cout<<"minimum spanning tree";
      printlist(head);

}
