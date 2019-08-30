# Introduction

OSGThreadPool is a thread pool implement based on OSG which is extracted from [VirtualPlanetBuilder](https://github.com/openscenegraph/VirtualPlanetBuilder).


# How to use

1. Add source file into your project.
2. Write your own osg::Operation.
2. Create a threadpool, add your operations, and wait for completion.


# Example

1. This is a Operation designed to resize a image with given file path and resize ratio.

```
class ResizeImageOperation : public osg::Operation
{
public:
	ResizeImageOperation(std::string strPath, float fltRatio) : m_strImagePath(strPath), m_fltRatio(fltRatio)
	{}

	virtual void operator () (osg::Object* object)
	{
		Mat img = imread(m_strImagePath);
    		Mat dst;
    		resize(img, dst, Size(), fltRratio, fltRratio);
    		imwrite(m_strImagePath);
	}
		
private:
	std::string	m_strImagePath;
	float		m_fltRatio;
};
```

2. White the main function. A threadpool is created with 8 threads running.

```
void main()
{
	std::vector<std::string> vecImagePath;
	GetImgPath("D:\\images", vecImagePath);
		
	osg::ref_ptr<ThreadPool> pThreadPool = new ThreadPool(8);
		
	for(int i = 0; i != vecImagePath.size(); i++)
		pThreadPool.run(new ResizeImageOperation(vecImagePath[i], 0.5));
				
	pThreadPool.waitForCompletion();
}
```
