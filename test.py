import exampleAPI

print(dir(exampleAPI))

print(exampleAPI.__doc__)

print(exampleAPI.pycAdd(1.0, 1.0))


uData = {"TestString":"This is James from Python"}

def myCallBack(uData):

    print(uData["TestString"])
    return 0


exampleAPI.pyPassFunc(myCallBack, uData)