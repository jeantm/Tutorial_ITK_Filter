#include <iostream>
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "multiThreadedOwnFilter.h"
#include "multiThreadedOwnFilterCLP.h"

int main( int argc, char * argv[] )
{
    PARSE_ARGS;
    
    if ( argc != 3 )
    {
        std::cerr << "Wrong Number of inputs for this main.\n" <<std::endl;
        return EXIT_FAILURE;
    }

    else
    {
        // Setup types
        typedef unsigned char InputPixelType;
        typedef unsigned char OutputPixelType;
        const unsigned int Dimension = 2;

        typedef itk::Image< InputPixelType, Dimension > InputImageType;
        typedef itk::Image< OutputPixelType, Dimension > OutputImageType;

        typedef itk::ImageFileReader< InputImageType > ReaderType;
        typedef itk::ImageFileWriter< OutputImageType > WriterType;

        typedef itk::MultiThreadedOwnFilter< InputImageType > FilterType;

        // Create the reader and the writer
        ReaderType::Pointer reader = ReaderType::New();
        WriterType::Pointer writer = WriterType::New();
        reader->SetFileName( input );
        writer->SetFileName( output );

        // Create the filter
        FilterType::Pointer filter = FilterType::New();
        filter->SetInput( reader->GetOutput() );
        filter->Update();
        writer->SetInput( filter->GetOutput() );
        writer->Update();

        return EXIT_SUCCESS;
    }

}
