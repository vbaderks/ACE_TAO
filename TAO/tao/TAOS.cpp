/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/TAOS.h"

#if !defined (__ACE_INLINE__)
#include "tao/TAOS.i"
#endif /* !defined INLINE */

#if defined (TAO_HAS_CORBA_MESSAGING)

// skeleton constructor
POA_TAO::ClientPriorityPolicy::ClientPriorityPolicy (void)
{

}

// skeleton destructor
POA_TAO::ClientPriorityPolicy::~ClientPriorityPolicy (void)
{
}

CORBA::Boolean POA_TAO::ClientPriorityPolicy::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/ClientPriorityPolicy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_TAO::ClientPriorityPolicy::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:TAO/ClientPriorityPolicy:1.0") == 0)
    return ACE_static_cast (POA_TAO::ClientPriorityPolicy_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Policy:1.0") == 0)
    return ACE_static_cast (POA_CORBA::Policy_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_TAO::ClientPriorityPolicy::_interface_repository_id (void) const
{
  return "IDL:TAO/ClientPriorityPolicy:1.0";
}

TAO::ClientPriorityPolicy*
POA_TAO::ClientPriorityPolicy::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  TAO::ClientPriorityPolicy *retval = 0;
  ACE_NEW_RETURN (
      retval,
      POA_TAO::_tao_direct_collocated_ClientPriorityPolicy (this, stub),
      0
    );
  return retval;
}

POA_TAO::_tao_direct_collocated_ClientPriorityPolicy::_tao_direct_collocated_ClientPriorityPolicy (
    POA_TAO::ClientPriorityPolicy_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_NESTED_CLASS (TAO,ClientPriorityPolicy) (),
    ACE_NESTED_CLASS (POA_CORBA,_tao_collocated_Policy) (servant, stub),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

CORBA::Boolean POA_TAO::_tao_direct_collocated_ClientPriorityPolicy::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}


POA_TAO::ClientPriorityPolicy_ptr POA_TAO::_tao_direct_collocated_ClientPriorityPolicy::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_TAO::_tao_direct_collocated_ClientPriorityPolicy::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_non_existent (ACE_TRY_ENV);
}


TAO::PrioritySpecification POA_TAO::_tao_direct_collocated_ClientPriorityPolicy::priority_specification  (
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->priority_specification (
      ACE_TRY_ENV
    );

}

// skeleton constructor
POA_TAO::BufferingConstraintPolicy::BufferingConstraintPolicy (void)
{

}

// skeleton destructor
POA_TAO::BufferingConstraintPolicy::~BufferingConstraintPolicy (void)
{
}

CORBA::Boolean POA_TAO::BufferingConstraintPolicy::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/BufferingConstraintPolicy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_TAO::BufferingConstraintPolicy::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:TAO/BufferingConstraintPolicy:1.0") == 0)
    return ACE_static_cast (POA_TAO::BufferingConstraintPolicy_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Policy:1.0") == 0)
    return ACE_static_cast (POA_CORBA::Policy_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_TAO::BufferingConstraintPolicy::_interface_repository_id (void) const
{
  return "IDL:TAO/BufferingConstraintPolicy:1.0";
}

TAO::BufferingConstraintPolicy*
POA_TAO::BufferingConstraintPolicy::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  TAO::BufferingConstraintPolicy *retval = 0;
  ACE_NEW_RETURN (
      retval,
      POA_TAO::_tao_direct_collocated_BufferingConstraintPolicy (this, stub),
      0
    );
  return retval;
}

POA_TAO::_tao_direct_collocated_BufferingConstraintPolicy::_tao_direct_collocated_BufferingConstraintPolicy (
    POA_TAO::BufferingConstraintPolicy_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_NESTED_CLASS (TAO,BufferingConstraintPolicy) (),
    ACE_NESTED_CLASS (POA_CORBA,_tao_collocated_Policy) (servant, stub),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

CORBA::Boolean POA_TAO::_tao_direct_collocated_BufferingConstraintPolicy::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}


POA_TAO::BufferingConstraintPolicy_ptr POA_TAO::_tao_direct_collocated_BufferingConstraintPolicy::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_TAO::_tao_direct_collocated_BufferingConstraintPolicy::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_non_existent (ACE_TRY_ENV);
}


TAO::BufferingConstraint POA_TAO::_tao_direct_collocated_BufferingConstraintPolicy::buffering_constraint  (
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->buffering_constraint (
      ACE_TRY_ENV
    );

}

TAO::BufferingConstraint POA_TAO::_tao_direct_collocated_BufferingConstraintPolicy::buffering_constraint  (void)
{
  return this->servant_->buffering_constraint ();

}

#endif /* TAO_HAS_CORBA_MESSAGING */
