#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *TestSummary_Create(void);
void TestSummary_Destroy(void *const obj);
void TestSummary_IncTotal(void *const obj);
void TestSummary_IncPass(void *const obj);
void TestSummary_IncFail(void *const obj);
void TestSummary_IncSkip(void *const obj);

void *TestResult_Create(void);
void TestResult_Destroy(void *const obj);
void TestResult_SetOk(void *const obj);
void TestResult_SetNg(void *const obj);
void TestResult_SetEc(void *const obj);

void *FileLocation_Create(void);
void FileLocation_Destroy(void *const obj);

inline void *__obj_create(uint32_t s)
{
    void *o = malloc(s);

    if (o)
    {
        (void)memset(o, 0, s);
    }
    return o;
}

inline void __obj_destroy(void *o)
{
    free(o);
}

typedef struct
{
    void *head;
    void *tail;
    uint32_t n;
} LinkedList;

typedef struct
{
    void *next;
} LinkedListNode;

void *LinkedList_Create(void)
{
    return __obj_create(sizeof(LinkedList));
}

void LinkedList_Destroy(void *const obj)
{
    __obj_destroy(obj);
}

void LinkedList_Push(void *const obj, void *const node)
{
    LinkedList *pll = (LinkedList *)obj;
    LinkedListNode *plln = (LinkedListNode *)node;
    LinkedListNode *pllp = NULL;

    if ((obj) && (node))
    {
        if (pll->head)
        {
            pll->head = node;
            pll->tail = node;
            pll->n++;

            plln->next = NULL;
        }
        else
        {
        }
    }
}

typedef struct
{
    uint32_t nrTotal;
    uint32_t nrPass;
    uint32_t nrFail;
    uint32_t nrSkip;
} TestSummary;

void *TestSummary_Create(void)
{
    return __obj_create(sizeof(TestSummary));
}

void TestSummary_Destroy(void *const obj)
{
    __obj_destroy(obj);
}

void TestSummary_IncTotal(void *const obj)
{
    if (obj)
    {
        ((TestSummary *)obj)->nrTotal++;
    }
}

void TestSummary_IncPass(void *const obj)
{
    if (obj)
    {
        ((TestSummary *)obj)->nrPass++;
    }
}

void TestSummary_IncFail(void *const obj)
{
    if (obj)
    {
        ((TestSummary *)obj)->nrFail++;
    }
}

void TestSummary_IncSkip(void *const obj)
{
    if (obj)
    {
        ((TestSummary *)obj)->nrSkip++;
    }
}

typedef struct
{
    uint8_t ok : 1;
    uint8_t ng : 1;
    uint8_t ec : 1;
} TestResult;

void *TestResult_Create(void)
{
    return __obj_create(sizeof(TestResult));
}

void TestResult_Destroy(void *const obj)
{
    __obj_destroy(obj);
}

void TestResult_SetOk(void *const obj)
{
    if (obj)
    {
        ((TestResult *)obj)->ok = 1;
    }
}

void TestResult_SetNg(void *const obj)
{
    if (obj)
    {
        ((TestResult *)obj)->ng = 1;
    }
}

void TestResult_SetEc(void *const obj)
{
    if (obj)
    {
        ((TestResult *)obj)->ec = 1;
    }
}

typedef struct
{
    char *file;
    uint32_t line;
} FileLocation;

void *FileLocation_Create(void)
{
    return __obj_create(sizeof(FileLocation));
}

void FileLocation_Destroy(void *const obj)
{
    __obj_destroy(obj);
}

void FileLocation_SetFile(void *const obj, char *str)
{
    if (obj)
    {
        ((FileLocation *)obj)->file = str;
    }
}

void FileLocation_SetLine(void *const obj, uint32_t line)
{
    if (obj)
    {
        ((FileLocation *)obj)->line = line;
    }
}

typedef struct
{
    char *name;
    char *msg;
} TestCase;

void *TestCase_Create(void)
{
    return __obj_create(sizeof(TestCase));
}

void TestCase_Destroy(void *const obj)
{
    __obj_destroy(obj);
}

typedef struct
{
    char *name;
    char *msg;
    void *topTestCase;
    uint32_t nrTestCase;
} TestSuite;

typedef struct
{
    TestSuite data;
    LinkedListNode node;
} TestSuiteNode;

void *TestSuite_Create(void)
{
    return __obj_create(sizeof(TestSuiteNode));
}

void TestSuite_Destroy(void *const obj)
{
    __obj_destroy(obj);
}

typedef struct
{
    void *topTestSuite;
    uint32_t nrTestSuite;
} TestRunner;

void *TestRunner_Create(void)
{
    return __obj_create(sizeof(TestRunner));
}

void TestRunner_Destroy(void *const obj)
{
    __obj_destroy(obj);
}

void TestRunner_PushTestSuite(void *const runner, void *const suite)
{
    TestRunner *r = runner;
    if ((runner) && (suite))
    {
        if (r->topTestSuite)
        {
            LinkedList_Push(&((TestSuiteNode *)r->topTestSuite)->node, suite);
        }
        else
        {
        }
        r->nrTestSuite++;
    }
}

int32_t main(void)
{
    return 0;
}