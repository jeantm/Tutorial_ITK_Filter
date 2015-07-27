#ifndef __multiThreadedOwnFilter_hxx
#define __multiThreadedOwnFilter_hxx
 
#include "multiThreadedOwnFilter.h"
#include "itkObjectFactory.h"
#include "itkImageRegionIterator.h"
#include "itkImageRegionConstIterator.h"
 
namespace itk
{
     
    template< class TImage>
    void MultiThreadedOwnFilter< TImage>::ThreadedGenerateData(const OutputImageRegionType & region,
                                                               ThreadIdType threadId)
    {
        typename TImage::ConstPointer inputPtr = this->GetInput(0);
        typename TImage::Pointer outputPtr = this->GetOutput(0);

        // Output a llocation memory
        this->AllocateOutputs();

        // Setup and create the iterator
        typedef itk::ImageRegionConstIterator< TImage > ConstIteratorType;
        typedef itk::ImageRegionIterator< TImage > IteratorType;
        ConstIteratorType cInputIt( inputPtr, inputPtr->GetRequestedRegion() );
        IteratorType outputIt( outputPtr, outputPtr->GetRequestedRegion() );
        
        // Filter the inputImage to negative
        cInputIt.GoToBegin();
        outputIt.GoToBegin();
        while ( !cInputIt.IsAtEnd() )
        {
            outputIt.Set( 255 - cInputIt.Get() );
            ++cInputIt;
            ++outputIt;
        }



    }

}// end namespace
 
 
#endif
