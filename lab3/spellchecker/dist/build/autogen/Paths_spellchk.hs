module Paths_spellchk (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch


version :: Version
version = Version {versionBranch = [1,0], versionTags = []}
bindir, libdir, datadir, libexecdir :: FilePath

bindir     = "/home/javier/.cabal/bin"
libdir     = "/home/javier/.cabal/lib/spellchk-1.0/ghc-7.6.3"
datadir    = "/home/javier/.cabal/share/spellchk-1.0"
libexecdir = "/home/javier/.cabal/libexec"

getBinDir, getLibDir, getDataDir, getLibexecDir :: IO FilePath
getBinDir = catchIO (getEnv "spellchk_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "spellchk_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "spellchk_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "spellchk_libexecdir") (\_ -> return libexecdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
