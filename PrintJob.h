#ifndef __PRINTJOB_H
#define __PRINTJOB_H

#include <iostream>
using namespace std;
#pragma once

class PrintJob {
    private:
        int priority;
        int jobNumber;
        int numPages;
    public:
        PrintJob(int setP, int setJ, int setN);
        int getPriority() const;
        int getJobNumber() const;
        int getPages() const;
};

#endif