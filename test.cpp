#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE wat
//#include <gmock/gmock.h>
#include <turtle/mock.hpp>
#include <boost/test/included/unit_test.hpp>

#include "Morse.h"

/*struct InitGMock {
    InitGMock() {
        
        //::testing::GTEST_FLAG(throw_on_failure) = true;
        //::gf_InitGMock(&boost::unit_test::framework::master_test_suite().argc,
                                  boost::unit_test::framework::master_test_suite().argv);
    }
    ~InitGMock() { }
};
BOOST_GLOBAL_FIXTURE(InitGMock);*/

MOCK_CLASS( mock_class )
{
    MOCK_METHOD(FileOpen, 1, bool(std::ifstream*), method)
    MOCK_METHOD(FileGet, 1, std::string(std::ifstream*), method2)
    MOCK_METHOD(GetResult, 0, std::string(), method3)
};

BOOST_AUTO_TEST_CASE( demonstrates_configuring_mock_objects )
{
    mock_class c;
    Morse m("MorseMap.csv");
    MOCK_EXPECT( c.method ).with(mock::any).returns( true );
    MOCK_EXPECT( c.method2 ).with(mock::any ).returns(".-");
    //MOCK_EXPECT( c.method3 );
    
    m.Decode("TestInput.txt");
    BOOST_CHECK_MESSAGE(m.GetResult() == "A", "Wrong! Should be" << c.GetResult());
    //BOOST_CHECK_MESSAGE(c.GetResult() == "A", "Wrong! " << c.GetResult());
}