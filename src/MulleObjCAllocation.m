//
//  MulleObjCAllocation.c
//  MulleObjC
//
//  Created by Nat! on 07.02.16.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "MulleObjCAllocation.h"

int   MulleObjCObjectZeroProperty( struct _mulle_objc_property *property, struct _mulle_objc_class *cls, void *self);

int   MulleObjCObjectZeroProperty( struct _mulle_objc_property *property, struct _mulle_objc_class *cls, void *self)
{
   char   *signature;
   
   signature = _mulle_objc_property_get_signature( property);
   switch( *signature)
   {
   case _C_PTR       :
   case _C_CHARPTR   :
   case _C_ASSIGN_ID :
   case _C_COPY_ID   :
   case _C_RETAIN_ID :
      if( property->setter)
         mulle_objc_object_inline_variable_selector_call( self, property->setter, NULL);
   }
   return( 0);
}


void   NSDeallocateObject( id self)
{
   if( self)
      _MulleObjCObjectFree( self);
}
