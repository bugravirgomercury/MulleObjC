#ifndef __MULLE_OBJC__
# import <Foundation/Foundation.h>
# pragma message "this test does not work with Apple Foundation"
#else
# import <MulleObjC/MulleObjC.h>
# import <MulleObjC/private/mulle-objc-universefoundationinfo-private.h>
#endif


main()
{
   NSThread                                    *thread;
   struct _mulle_objc_universefoundationinfo   *config;
   struct _mulle_objc_universe                 *universe;

   universe = mulle_objc_global_get_defaultuniverse();
   config   = _mulle_objc_universe_get_universefoundationinfo( universe);
   if( _mulle_atomic_pointer_read( &config->thread.n_threads) != (void *) 1)
   {
      printf( "not running in universe %p\n", universe);
      return( 1);
   }

   thread = [NSThread currentThread];  // it should be available already
   if( ! thread)
   {
      printf( "missing NSThread in universe %p\n", universe);
      return( 1);
   }

   fprintf( stderr, "1\n");

   //
   // thread must not be a rootobject
   // thread must be a rootthreadobject
   //
   if( mulle_set_get( config->object.roots, thread))
      printf( "is mistakingly root object\n");
   if( ! mulle_set_get( config->object.threads, thread))
      printf( "is mistakingly not a root thread object\n");

   fprintf( stderr, "2\n");
   _mulle_objc_universe_release( universe);
   fprintf( stderr, "3\n");

   // DANGEROUS!
   if( _mulle_atomic_pointer_read( &config->thread.n_threads) != (void *) 0)
   {
      printf( "still running\n");
      return( 1);
   }
   fprintf(  stderr, "4\n");
   return( 0);
}
