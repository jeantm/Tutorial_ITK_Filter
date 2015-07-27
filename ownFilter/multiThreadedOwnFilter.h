#ifndef __multiThreadedOwnFilter_h
#define __multiThreadedOwnFilter_h
 
#include "itkImageToImageFilter.h"
 
namespace itk
{
    template< class TImage>
    class MultiThreadedOwnFilter:public ImageToImageFilter< TImage, TImage >
    {
    public:
        /** Standard class typedefs. */
        typedef MultiThreadedOwnFilter             Self;
        typedef ImageToImageFilter< TImage, TImage > Superclass;
        typedef SmartPointer< Self >        Pointer;

        typedef typename Superclass::OutputImageRegionType OutputImageRegionType;

        /** Method for creation through the object factory. */
        itkNewMacro(Self);

        /** Run-time type information (and related methods). */
        itkTypeMacro(MultiThreadedOwnFilter, ImageToImageFilter);

    protected:
        MultiThreadedOwnFilter(){}
        ~MultiThreadedOwnFilter(){}

        /** Does the real work. */
        virtual void ThreadedGenerateData(const OutputImageRegionType & region,
                                          ThreadIdType threadId);

    private:
        MultiThreadedOwnFilter(const Self &); //purposely not implemented
        void operator=(const Self &);  //purposely not implemented
    };
} //namespace ITK
 
 
#ifndef ITK_MANUAL_INSTANTIATION
#include "multiThreadedOwnFilter.hxx"
#endif
 
 
#endif // __itkMultiThreadedOwnFilter_h
