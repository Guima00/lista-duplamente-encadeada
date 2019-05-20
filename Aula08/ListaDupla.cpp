#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(primeiro);
    p->setAnt(NULL);

    if(n == 0)
        ultimo = p;
    else
        primeiro->setAnt(p);

    primeiro = p;
    n = n + 1;
}

void ListaDupla::removeInicio()
{
    NoDuplo *p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;
        n = n - 1;

        if(n == 0)
            ultimo = NULL;
        else
            primeiro->setAnt(NULL);
    }
    else
        cout << "ERRO: lista vazia" << endl;
}
void ListaDupla::insereFinal(int val)
{
    NoDuplo *p=new NoDuplo();
    p->setInfo(val);
    p->setAnt(ultimo);
    p->setProx(NULL);
    if(n!=0)
    {
        ultimo->setProx(p);
    }
    else
    {
        primeiro=p;
    }
    ultimo=p;
    n++;
}
void ListaDupla::removeFinal()
{
    NoDuplo *p;
    if(n==0)
    {
        cout<<"nao possui nenhum no"<<endl;
    }
    else
    {
        p=ultimo;
        ultimo=p->getAnt();
        delete p;
        n--;
        if(n==0)
        {
            primeiro=NULL;
        }
        else
            ultimo->setProx(NULL);

    }
}
void ListaDupla::removeOcorrencias(int val)
{
    if(n!=0)
    {
        NoDuplo *aux=primeiro;
        while(aux!=NULL)
        {
            NoDuplo *p=aux;
            aux=aux->getProx();
            if(p->getInfo()==val)
            {
                (p->getProx())->setAnt(p->getAnt());
                (p->getAnt())->setProx(p->getProx());
                delete p;
                NoDuplo *p=aux;
            }
        }
    }
    else
    {
        cout<<"nn a nos"<<endl;
    }
}
