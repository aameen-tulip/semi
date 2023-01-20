/* ========================================================================== *
 *
 *
 *
 * -------------------------------------------------------------------------- */

#pragma once

#include <string>
#include <vector>

#include "semver.hh"

/* -------------------------------------------------------------------------- */

namespace semi {

/* -------------------------------------------------------------------------- */

  struct Comparator {

/* -------------------------------------------------------------------------- */

    /* Data Members */

    std::string raw;
    std::string op;
    std::string value;
    SemVer      semver;

    /**
     * Normally "max version" ranges will prefer lower versions if higher
     * versioned candidates are tagged with a pre-release suffix.
     * This option allows pre-release versions to satisfy ranges even if they
     * don't explicitly opt into the use of pre-release specifiers.
     */
    bool includePrerelease;

    /**
     * Interpret version ranges loosely.
     * This allows non-compliant ranges to be normalized without errors.
     * Specifically this allows "00.01.002" to be read as "0.1.2"
     */
    bool loose;


/* -------------------------------------------------------------------------- */

    Comparator(
      std::string comp              = "",
      bool        includePrerelease = false,
      bool        loose             = false
    );

    Comparator(
      std::string op,
      SemVer      semver,
      bool        includePrerelease = false,
      bool        loose             = false
    );

    Comparator(
      std::string op,
      std::string semver,
      bool        includePrerelease = false,
      bool        loose             = false
    );


/* -------------------------------------------------------------------------- */

    void parseComparator( std::string comp );


/* -------------------------------------------------------------------------- */

    /* Comparators */

    bool intersects(
      const Comparator & other,
            bool         includePrerelease = false,
            bool         loose             = false
    );

    bool test( const SemVer version );
    bool test( const std::string version );


/* -------------------------------------------------------------------------- */

    /* Serializers */

    std::string toString();


/* -------------------------------------------------------------------------- */

  };  /* End struct `Comparator' */


/* -------------------------------------------------------------------------- */

}  /* End Namespace `semi' */

/* -------------------------------------------------------------------------- *
 *
 *
 *
 * ========================================================================== */
