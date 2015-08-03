#include <iostream>
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkMedianImageFilter.h"


int main(int argc, char ** argv)
{
    if (argc != 3)
    {
        std::cerr << "Wrong Number of inputs for this main.\n" <<std::endl;
        return EXIT_FAILURE;
    }

    else
    {
        typedef unsigned char InputPixelType;
        typedef unsigned char OutputPixelType;
        const unsigned int Dimension = 2;
        
        typedef itk::Image< InputPixelType, Dimension > InputImageType;
        typedef itk::Image< OutputPixelType, Dimension > OutputImageType;

        typedef itk::ImageFileReader< InputImageType > ReaderType;
        typedef itk::ImageFileWriter< OutputImageType > WriterType;

        ReaderType::Pointer reader = ReaderType::New();
        WriterType::Pointer writer = WriterType::New();
        reader->SetFileName( argv[1] );
        writer->SetFileName( argv[2] );

        typedef itk::MedianImageFilter< InputImageType, OutputImageType > FilterType;
        FilterType::Pointer filter = FilterType::New();

        InputImageType::SizeType indexRadius;
        indexRadius[0] = 1; // radius along x
        indexRadius[1] = 1; // radius along y
        filter->SetRadius( indexRadius );

        filter->SetInput( reader->GetOutput() );
        writer->SetInput( filter->GetOutput() );
        writer->Update();

        return EXIT_SUCCESS;
    }
    
}
