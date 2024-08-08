#include "PrintJob.h"
/* PrintJob Default Constructor */
// sets priority, job number, and num pages to given parameter values
PrintJob::PrintJob(int setP, int setJ, int numP) : priority(setP), jobNumber(setJ), numPages(numP) {}
/* Const Accessor functions */
int PrintJob::getPriority() const { return priority; }
int PrintJob::getJobNumber() const { return jobNumber; }
int PrintJob::getPages() const { return numPages; }