#ifndef __ownFilter_h
#define __ownFilter_h
 
#include "itkImageToImageFilter.h"
 
namespace itk
{
    template< class TImage>
    class OwnFilter:public ImageToImageFilter< TImage, TImage >
    {
    public:
        /** Standard class typedefs. */
        typedef OwnFilter             Self;
        typedef ImageToImageFilter< TImage, TImage > Superclass;
        typedef SmartPointer< Self >        Pointer;

        /** Method for creation through the object factory. */
        itkNewMacro(Self);

        /** Run-time type information (and related methods). */
        itkTypeMacro(OwnFilter, ImageToImageFilter);

    protected:
        OwnFilter(){}
        ~OwnFilter(){}

        /** Does the real work. */
        virtual void GenerateData();

    private:
        OwnFilter(const Self &); //purposely not implemented
        void operator=(const Self &);  //purposely not implemented
    };
} //namespace ITK
 
 
#ifndef ITK_MANUAL_INSTANTIATION
#include "ownFilter.hxx"
#endif
 
 
#endif // __itkOwnFilter_h
