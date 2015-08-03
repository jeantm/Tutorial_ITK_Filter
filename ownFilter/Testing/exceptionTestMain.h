#ifndef EXCEPTIONTESTMAIN_H
#define EXCEPTIONTESTMAIN_H




// This file is used to create TestDriver executables
// These executables are able to register a function pointer to a string name
// in a lookup table. By including this file, it creates a main function
// that calls RegisterExceptionTests() then looks up the function pointer for the test
// specified on the command line.

#include "itkMacro.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "itkMultiThreader.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionConstIterator.h"
#include "itkSubtractImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkExtractImageFilter.h"
#if ITK_VERSION_MAJOR < 4
#include "itkDifferenceImageFilter.h"
#else
#include "itkTestingComparisonImageFilter.h"
#endif
#include "itksys/SystemTools.hxx"
#include "itkIntTypes.h"
#include "itkFloatingPointExceptions.h"


#define ITK_TEST_DIMENSION_MAX 6
typedef int ( *MainFuncPointer )(int, char *[]);
std::map<std::string, MainFuncPointer> StringToTestFunctionMap;

#define REGISTER_TEST(exceptionTest) \\
extern int exceptionTest(int, char *[]); \
StringToTestFunctionMap[#exceptionTest] = exceptionTest
void RegisterExceptionTests();
void PrintAvailableExceptionTests();

int main(int ac, char *av[])
{
    itk::FloatingPointExceptions::Enable();
    RegisterExceptionTests();
    std::string exceptionTestToRun = av[1];

    std::map<std::string, MainFuncPointer>::iterator j = StringToTestFunctionMap.find(exceptionTestToRun);

    if( j != StringToTestFunctionMap.end() )
    {
        MainFuncPointer f = j->second;
        int result;

        try
        {
            // Invoke the test's "main" function.
            result = ( *f )( ac - 1, av + 1 );
        }
        catch( itk::ExceptionObject& e )
        {
            std::cerr << "\n\n\nException detected :\n\t" << e.what() << "\n\n\n" << std::endl;
            return 0;
        }
        catch( ... )
        {
            std::cerr << "\n\n\nOther Exception detected\n\n\n" << std::endl;
            return -1;
        }
        return result;

    }
    PrintAvailableExceptionTests();
    std::cerr << "Failed: " << exceptionTestToRun << ": No test registered with name " << exceptionTestToRun << "\n";
    return -1;
}


void PrintAvailableExceptionTests()
{
    std::cout << "Available exception tests:\n";
    std::map<std::string, MainFuncPointer>::iterator j = StringToTestFunctionMap.begin();
    int i = 0;
    while( j != StringToTestFunctionMap.end() )
    {
        std::cout << i << ". " << j->first << "\n";
        ++i;
        ++j;
    }
}

#endif // EXCEPTIONTESTMAIN_H
