// $Id$
//
// ============================================================================
//
// = LIBRARY
//    FT
//
// = FILENAME
//    FT_Callbacks.h
//
// = DESCRIPTION
//   A concrete FT service callback implementation
//
// = AUTHOR
//   Bala Natarajan <bala@cs.wustl.edu>
// ============================================================================
#ifndef TAO_FT_CALLBACKS_H
#define TAO_FT_CALLBACKS_H
#include "ace/pre.h"

#include "fault_tol_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Service_Callbacks.h"
class TAO_Profile;
class TAO_MProfile;

class TAO_FT_Export TAO_FT_Service_Callbacks : public TAO_Service_Callbacks
{
  // = TITLE
  //   A class to dynamically load the FT callback implementations in
  //   to the ORB.
  //
  // = DESCRIPTION
  //   An implementation of the service callbacks that allows the
  //   loading of the FT ORB level library in to the ORB
public:
  TAO_FT_Service_Callbacks (void);
  // Constructor

  virtual CORBA::Boolean  select_profile (TAO_MProfile *mprofile,
                                          TAO_Profile *&pfile);
  // This method would search the list of <mprofile> to identify a
  // TAG_FT_PRIMARY and set that profile as <pfile>.

  virtual CORBA::Boolean  reselect_profile (TAO_Stub* stub,
                                            TAO_Profile *&pfile);

  // This method would search the IOR list for the first non-primary
  // in case of primary failure.

  virtual void reset_profile_flags (void);
  // Reset any of the local flags that we may have

  virtual CORBA::Boolean object_is_nil (CORBA::Object_ptr obj);
  // Check whether <obj> is nil or not. FT spec suggests some
  // extensions for a CORBA::is_nil () operation.


  // Need to do is_equivalent and hash also here
private:

  CORBA::Boolean primary_failed_;
  // A flag that indicates that the primary has already failed. So any
  // more calls to select_profile () should not reset the profile
  // pointer to the primary.

  CORBA::Boolean secondary_set_;
  // A flag to indicate that a secondary has been selected for
  // invocation. We do this only once in the cycle. When we get there
  // again we dont select a primary again and again.
};

#if defined (__ACE_INLINE__)
# include "FT_Service_Callbacks.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /*TAO_FT_CALLBACKS_H*/
