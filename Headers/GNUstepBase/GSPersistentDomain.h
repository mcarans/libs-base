/** Implementation for GSPersistentDomain for GNUstep
   Copyright (C) 1995-2016 Free Software Foundation, Inc.

   Written by:  Georg Tuparev <Tuparev@EMBL-Heidelberg.de>
                   EMBL & Academia Naturalis,
                Heidelberg, Germany
   Modified by:  Richard Frith-Macdonald <rfm@gnu.org>

   This file is part of the GNUstep Base Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 31 Milk Street #960789 Boston, MA 02196 USA.

*/

#ifndef	__GSPersistentDomain_h_GNUSTEP_BASE_INCLUDE
#define	__GSPersistentDomain_h_GNUSTEP_BASE_INCLUDE

#import <Foundation/NSKeyValueCoding.h>
#import <Foundation/NSPropertyList.h>
#import <Foundation/NSUserDefaults.h>

#if	defined(__cplusplus)
extern "C" {
#endif

/* An instance of the GSPersistentDomain class is used to encapsulate
 * a single persistent domain (represented as a property list file in
 * the defaults directory.
 * Instances are generally created without contents, and the contents
 * are lazily loaded from disk when the domain is needed (either because
 * it is in the defaults system search list, or because the method to
 * obtain a copy of the domain contents is called).
 */
GS_EXPORT_CLASS
@interface GSPersistentDomain : NSObject
{
@private
  NSString		*name;
  NSString		*path;
  NSUserDefaults	*owner;
  NSMutableDictionary	*contents;
  NSMutableSet          *added;
  NSMutableSet          *modified;
  NSMutableSet          *removed;
  BOOL                  loaded;
}

/** Returns the property list format to use when saving property list
 * file. The default is NSPropertyListXMLFormat_v1_0. This can be
 * overridden in a category.
 */
- (NSPropertyListFormat)propertyListFormat;
@end

#if	defined(__cplusplus)
}
#endif

#endif	/* __GSPersistentDomain_h_GNUSTEP_BASE_INCLUDE */
