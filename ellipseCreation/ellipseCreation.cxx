#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionIterator.h"


int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        printf("Wrong Number of inputs for this main./n");
        return EXIT_FAILURE;
    }

    else
    {
        // Image parameters and configuration
        typedef itk::Image< unsigned char, 2 >  ImageType;
        ImageType::RegionType region;
        ImageType::IndexType start;
        start[0] = 0;
        start[1] = 0;
        ImageType::SizeType size;
        size[0] = 200;
        size[1] = 300;
        region.SetSize(size);
        region.SetIndex(start);

        ImageType::Pointer image = ImageType::New();
        image->SetRegions(region);
        image->Allocate();
        
        // Writer configuration
        typedef itk::ImageFileWriter< ImageType > WriterType;
        WriterType::Pointer writer = WriterType::New();
        writer->SetFileName( argv[1] );
        
        // Iterator configuration
        typedef itk::ImageRegionIterator< ImageType > IteratorType;
        IteratorType cIt( image, image->GetRequestedRegion() );

        for ( cIt.GoToBegin(); !cIt.IsAtEnd(); ++cIt )
        {
            int xc = cIt.GetIndex()[0] - size[0]/4;
            int yc = cIt.GetIndex()[1] - size[1]/4;
            int radius = 15;
            
            int x = cIt.GetIndex()[0] - size[0]/2;
            int y = cIt.GetIndex()[1] - size[1]/2;
            int a = 20;
            int b = 6;
            

            if ( ( ( xc*xc )+( yc*yc ) < ( radius*radius ) ) || ( ( ( x*x )/( a*a )+( y*y )/( b*b ) ) < 1 ) )
            //if ( ( ( x*x )/( a*a )+( y*y )/( b*b ) ) < 1 )
            {
                cIt.Set( 255 );
            }

            else cIt.Set( 0 );
        }



        writer->SetInput( image );
        writer->Update();

        return EXIT_SUCCESS;
    }
    
}
