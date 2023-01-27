#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  uint32_t nrTotal;
  uint32_t nrPass;
  uint32_t nrFail;
  uint32_t nrSkip;
} TestSummary;

void *TestSummary_Create(void) {
  void *obj = malloc(sizeof(TestSummary));

  if (obj) {
    (void)memset(obj, 0, sizeof(TestSummary));
  }
  return obj;
}

void TestSummary_Destroy(void *const obj) {
  if (obj) {
    free(obj);
  }
}

void TestSummary_IncTotal(void *const obj) {
  if (obj) {
    ((TestSummary *)obj)->nrTotal++;
  }
}

void TestSummary_IncPass(void *const obj) {
  if (obj) {
    ((TestSummary *)obj)->nrPass++;
  }
}

void TestSummary_IncFail(void *const obj) {
  if (obj) {
    ((TestSummary *)obj)->nrFail++;
  }
}

void TestSummary_IncSkip(void *const obj) {
  if (obj) {
    ((TestSummary *)obj)->nrSkip++;
  }
}

typedef struct {
  uint8_t ok: 1;
  uint8_t ng: 1;
  uint8_t ec: 1;
} TestResult;

void *TestResult_Create(void) {
  void *obj = malloc(sizeof(TestResult));

  if (obj) {
    (void)memset(obj, 0, sizeof(TestResult));
  }
  return obj;
}

void TestResult_Destroy(void *const obj) {
  if (obj) {
    free(obj);
  }
}

void TestResult_SetOk(void *const obj) {
  if (obj) {
    ((TestResult *)obj)->ok = 1;
  }
}

void TestResult_SetNg(void *const obj) {
  if (obj) {
    ((TestResult *)obj)->ng = 1;
  }
}

void TestResult_SetEc(void *const obj) {
  if (obj) {
    ((TestResult *)obj)->ec = 1;
  }
}

int32_t main(void) { return 0; }