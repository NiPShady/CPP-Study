#include<iostream>
#include<memory>
#include<string>
#include "unique_ptr.h"

class Entity
{	
public:
	Entity() {
		std::cout << "Create Entity!" << std::endl;
	}
	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
	void Print(){}
};

int main()
{
	{
		std::shared_ptr<Entity> e0;//��sharedEntity���ڵĿ�����������,e0��Ȼ����ָ��sharedEntityָ����ڴ�,ֱ��e0���ڵĿ���������e0���Զ�����
		//�����������µĿ�����
		{
			//��ʽΪstd::unique_ptr <ģ��/��> ������ = std::make_unique<ģ��/��>();
			std::unique_ptr<Entity> entity = std::make_unique<Entity>(); //unique_ptr����ʱ��������ʽ����ת��,������ʽ���ù��캯�� ͬʱʹ��std::make_unique��֤��ȫ��(�ڹ��캯���׳��쳣ʱ���᷵��û�����õ�����ָ���Ե����ڴ�й¶)

			entity->Print(); //���������ڿ�������ָͨ��һ��ʹ��unique_ptr,�뿪��ҵ��ָ��entity���Զ�����,���ǲ����Ը���unique_ptr,���ʹԭָ�������ٺ���ָ���ΪҰָ������ڴ�й¶
			//��Ҫ����unique_ptrʱʹ��std::shared_ptr,�����ǽ�unique_ptr������ָ��
			//std::shared_ptr�������ü���,��ָ������Ϊ��ʱ,�Զ�����shared_ptr
			//��ʽΪstd::shared_ptr <ģ��/��> ������ = std::make_shared<ģ��/��>();
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); //std::shared_ptr�в�ʹ��new�ؼ�����ӦΪshared_ptr��Ҫ������һ���ڴ�(���ƿ�)�洢���ü���,��ʹ��new�ؼ��ֻᵼ��2���ڴ����
			e0 = sharedEntity;
			//shared_ptr��ֵ��shared_ptrʱ���������ü���,���Ǹ�ֵ��weak_ptrʱ����
			//weak_ptr��ָ��,��������shared_ptr�����ü���,��ͬ��weak_ptrҲ�����shared_ptrһ�����
			std::weak_ptr<Entity> weakEntity = sharedEntity;  //weak_ptr���Ա�ѯ���Ƿ���Ч(�Ƿ�ָ��Ϊ��)

		}
	}
	std::cin.get();
}