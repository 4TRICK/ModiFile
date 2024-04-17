QtModule {
    qtModuleName: "Widgets"
    Depends { name: "Qt"; submodules: ["core","gui"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6Widgets"
    libNameForLinkerRelease: "Qt6Widgets"
    libFilePathDebug: undefined
    libFilePathRelease: "A:/qt/6.7.0/mingw_64/lib/libQt6Widgets.a"
    pluginTypes: ["styles"]
    moduleConfig: ["shared"]
    cpp.defines: ["QT_WIDGETS_LIB"]
    cpp.systemIncludePaths: ["A:/qt/6.7.0/mingw_64/include","A:/qt/6.7.0/mingw_64/include/QtWidgets"]
    cpp.libraryPaths: []
    Group {
        files: libFilePath
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
