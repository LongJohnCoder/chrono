// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Radu Serban
// =============================================================================
//
// M113 idler subsystem.
//
// =============================================================================

#ifndef M113_DOUBLE_IDLER_H
#define M113_DOUBLE_IDLER_H

#include <string>

#include "chrono_vehicle/ChSubsysDefs.h"
#include "chrono_vehicle/tracked_vehicle/idler/ChDoubleIdler.h"

namespace m113 {

///
///
///
class M113_Idler : public chrono::vehicle::ChDoubleIdler {
  public:
    M113_Idler(chrono::vehicle::VisualizationType vis_type);
    ~M113_Idler() {}

    /// Return the mass of the idler wheel body.
    virtual double GetWheelMass() const override { return m_wheel_mass; }
    /// Return the moments of inertia of the idler wheel body.
    virtual const chrono::ChVector<>& GetWheelInertia() override { return m_wheel_inertia; }
    /// Return the radius of the idler wheel.
    virtual double GetWheelRadius() const override { return m_wheel_radius; }
    /// Return the total width of the idler wheel.
    virtual double GetWheelWidth() const override { return m_wheel_width; }
    /// Return the gap width.
    virtual double GetWheelGap() const override { return m_wheel_gap; }

    /// Return the mass of the carrier body.
    virtual double GetCarrierMass() const override { return m_carrier_mass; }
    /// Return the moments of inertia of the carrier body.
    virtual const chrono::ChVector<>& GetCarrierInertia() override { return m_carrier_inertia; }
    /// Return a visualization radius for the carrier body.
    virtual double GetCarrierVisRadius() const override { return m_carrier_radius; }

    /// Return the pitch angle of the prismatic joint.
    virtual double GetPrismaticPitchAngle() const override { return 0; }

    /// Return the free (rest) length of the spring element of the tensioner.
    virtual double GetTensionerRestLength() const override { return m_tensioner_free_length; }
    /// Return the callback function for spring force.
    virtual chrono::ChSpringForceCallback* GetTensionerForceCallback() const override { return m_tensionerForceCB; }

    /// Initialize this idler subsystem.
    virtual void Initialize(chrono::ChSharedPtr<chrono::ChBodyAuxRef> chassis,  ///< [in] handle to the chassis body
                            const chrono::ChVector<>& location  ///< [in] location relative to the chassis frame
                            ) override;

  private:
    chrono::ChSpringForceCallback* m_tensionerForceCB;

    static const double m_wheel_mass;
    static const chrono::ChVector<> m_wheel_inertia;
    static const double m_wheel_radius;
    static const double m_wheel_width;
    static const double m_wheel_gap;

    static const double m_carrier_mass;
    static const chrono::ChVector<> m_carrier_inertia;
    static const double m_carrier_radius;

    static const double m_tensioner_free_length;

    chrono::vehicle::VisualizationType m_vis_type;
    static const std::string m_meshName;
    static const std::string m_meshFile;
};

}  // end namespace m113

#endif
