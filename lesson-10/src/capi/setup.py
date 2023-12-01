from setuptools import setup, Extension

def main():
    setup(
        name="cutils",
        author="A.A.Kukhtichev",
        version="0.0.2",
        ext_modules=[Extension('cutils', ['cutils.c'])]
    )

if __name__ == "__main__":
    main()
