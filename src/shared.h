/* central file for utility functions */

// system headers
#include <string>

// library headers
#include <QString>

// makes an existing file executable
bool makeExecutable(const std::string& path);

enum IntegrationState {
    INTEGRATION_FAILED = 0,
    INTEGRATION_SUCCESSFUL,
    INTEGRATION_ABORTED
};

// installs desktop file for given AppImage, including AppImageLauncher specific modifications
// set resolveCollisions to false in order to leave the Name entries as-is
bool installDesktopFile(const QString& pathToAppImage, bool resolveCollisions = true);

// update AppImage's existing desktop file with AppImageLauncher specific entries
// this alias for installDesktopFile does not perform any collision detection and resolving
bool updateDesktopFile(const QString& pathToAppImage);

// update desktop database and icon caches of desktop environments
// this makes sure that:
//   - outdated entries are removed from the launcher
//   - icons of freshly integrated AppImages are displayed in the launcher
bool updateDesktopDatabaseAndIconCaches();

// integrates an AppImage using a standard workflow used across all AppImageLauncher applications
IntegrationState integrateAppImage(const QString& pathToAppImage, const QString& pathToIntegratedAppImage);

// standard location for integrated AppImages
// currently hardcoded, can not be changed by users
static const auto integratedAppImagesDestination = QString(getenv("HOME")) + "/Applications/";

// build path to standard location for integrated AppImages
QString buildPathToIntegratedAppImage(const QString& pathToAppImage);

// get AppImage MD5 digest
// extracts the digest embedded in the file
// if no such digest has been embedded, it calculates it using libappimage
QString getAppImageDigestMd5(const QString& path);

// checks whether AppImage has been integrated already
bool hasAlreadyBeenIntegrated(const QString& pathToAppImage);

// checks whether AppImage is in a previous AppImage destination, and should be moved to new directory
bool isInOldApplicationsDirectory(const QString& pathToAppImage);
