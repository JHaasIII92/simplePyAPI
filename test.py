import exampleAPI

print(dir(exampleAPI))

print(exampleAPI.__doc__)

print(exampleAPI.pycAdd(1.0, 1.0))


uData = {"TestString":"This is from Python!"}

def myCallBack(cData, uData):
    print(cData)
    print(uData["TestString"])
    return 0


exampleAPI.pySetCallBack(myCallBack, uData)

for i in range(1,10):
    exampleAPI.pyCallBack()