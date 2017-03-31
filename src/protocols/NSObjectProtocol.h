//
//  NSObjectProtocol.h
//  MulleObjC
//
//  Copyright (c) 2011 Nat! - Mulle kybernetiK.
//  Copyright (c) 2011 Codeon GmbH.
//  All rights reserved.
//
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//  Neither the name of Mulle kybernetiK nor the names of its contributors
//  may be used to endorse or promote products derived from this software
//  without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
#import "ns_objc_type.h"
#import "ns_int_type.h"

#import "ns_zone.h"


#ifdef TRACE_INCLUDE_MULLE_FOUNDATION
# warning NSObject protocol included
#endif


@protocol NSObject

- (nonnull instancetype) retain;
- (void) release;
- (nonnull instancetype) autorelease;
- (NSUInteger) retainCount;

- (Class) superclass;
- (nonnull Class) class;
- (nonnull id) self;

- (id) performSelector:(SEL) sel;
- (id) performSelector:(SEL) sel
            withObject:(id) obj;
- (id) performSelector:(SEL) sel
            withObject:(id) obj
            withObject:(id) other;
- (BOOL) isProxy;
- (BOOL) isKindOfClass:(Class) cls;
- (BOOL) isMemberOfClass:(Class) cls;
- (BOOL) conformsToProtocol:(PROTOCOL) protocol;
- (BOOL) respondsToSelector:(SEL) sel;


// these are not in the traditional NSObject protocol
+ (instancetype) new;
+ (nonnull instancetype) alloc;
+ (nonnull instancetype) allocWithZone:(NSZone *) zone;  // deprecated
- (instancetype) init;

- (BOOL) isEqual:(id) obj;
- (NSUInteger) hash;
- (id) description;

// mulle additions:

// AAO suport
+ (nonnull instancetype) instantiate;
- (nonnull instancetype) immutableInstance;

// advanced Autorelease and ObjectGraph support
- (void) _becomeRootObject;
- (void) _pushToParentAutoreleasePool;

@end
